// credit: Yiheng Yao

#include<cstdlib>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

struct state{
	int heuCost = 0;
	int n = 0;
	int pour = 0;
	int cups[5] = {0,0,0,0,0};
	state(int n, int* in_cups): n(n) {
		for (int i=0;i<n;++i) cups[i] = in_cups[i];
	}
	bool operator<(const state& rhs) const{
		return heuCost < rhs.heuCost;
	}
	bool operator>(const state& rhs) const{
		return heuCost > rhs.heuCost;
	}
	bool operator==(const state& other) const{
		if (n != other.n) return false;
		bool cup_same = true;
		for (int i=0;i<n;++i){
			if (cups[i] != other.cups[i]){
				return false;
			}
		}
		return true;
	}
};

struct stateHasher{
	size_t operator()(const state& k) const{
		using std::hash;
		size_t res = 0;
//		res = res * 31 + hash<int>()(k.pour);
		string s = "";
		for (int i=0;i<k.n;++i){
			s += (char) k.cups[i];
//			res = res | res << 8;
//			printf("%d", k.cups[i]);
		}
//		printf("<%s>\n", s.c_str());
//		return hash<string>()(s);
		res = res * 31 + hash<string>()(s);
		return res;
	}
};

int heuristic(int goal, state& s){
	return abs(goal-s.cups[0]);
//	return 0;
}

void debug_state(state& s){
	return;
	for (int i=0;i<s.n;++i) printf("%d ", s.cups[i]);
	printf("[%d]\n", s.pour);
}

int N, goal;
int cups[5];
int capacity[5];
priority_queue<state, vector<state>, greater<state>> q;
unordered_map<state, int, stateHasher> v;
int main(){
	scanf("%d", &N);
	for (int i=0;i<N;++i){
		scanf("%d",&capacity[i]);
	}
	cups[0] = capacity[0];
	scanf("%d", &goal);
	
//	for (int i=0;i<N;++i) printf("%d ", capacity[i]);
//	printf("|%d\n", goal);
	
	state init_state = state(N, &cups[0]);
	debug_state(init_state);
	
	int new_cost = 0;
	int new_heuCost = heuristic(goal, init_state);
	init_state.pour = new_cost;
	init_state.heuCost = new_cost + new_heuCost;
	q.push(init_state);
	
	while(!q.empty()){
		state cur_state = q.top();
		q.pop();

		if (v.find(cur_state) != v.end() && v.at(cur_state) <= cur_state.pour){
			continue;
		}
		v.insert({cur_state, cur_state.pour});
		
		debug_state(cur_state);
		
		if (cur_state.cups[0] == goal){
			printf("%d\n", cur_state.pour);
			return 0;
		}

		for (int i=0;i<N;++i){
			for (int j=0;j<N;++j){
				if (i == j) continue;
				if (cur_state.cups[i] > 0 && cur_state.cups[j] < capacity[j]){
					int poured = min(cur_state.cups[i], capacity[j] - cur_state.cups[j]);
					int new_cups[5];
					for (int k=0;k<5;++k) new_cups[k] = cur_state.cups[k];
					new_cups[i] -= poured;
					new_cups[j] += poured;
					state newState = state(N, &new_cups[0]);
					int newCost = cur_state.pour + poured;
					int heuCost = heuristic(goal, newState);
					newState.pour = newCost;
					newState.heuCost = newCost + heuCost;
					if (v.find(newState) == v.end() || v.at(newState) > newCost){
						q.push(newState);
//						v.insert({newState, newCost});
					}
				}
				// Invalid otherwise
			}
		}
	}
	printf("impossible\n");
	return 0;
}
