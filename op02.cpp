#include <bits/stdc++.h>
using namespace std;

struct Proc {
int pid; // process ID
int arrival; // arrival time
int burst; // total CPU burst required
int remaining; // remaining CPU time
int first_start; // first time scheduled (for response time)
int finish; // completion time
int last_enq; // last time (re)enqueued (for aging)
};

struct Event { int t, pid, q; }; // for Gantt chart (start time t, pid at queue q)

int main(int argc, char** argv) {
ios::sync_with_stdio(false);
cin.tie(nullptr);

// Queues: Q0, Q1, Q2... higher index -> lower priority, larger quantum
vector<int> quanta = {2, 4, 8, 16};
int aging_threshold = 20; // if waiting > threshold, promote one level

vector<Proc> procs;
// Built-in workload (pid, arrival, burst)
vector<tuple<int,int,int>> wb = {
{1, 0, 12}, {2, 1, 7}, {3, 2, 20}, {4, 6, 5}, {5, 10, 10}
};

// Optional: read workload from file: lines of "pid arrival burst"
if (argc == 3 && string(argv[1]) == string("--workload")) {
ifstream fin(argv[2]);
if (!fin) { cerr << "Cannot open workload file\n"; return 1; }
wb.clear();
int p,a,b; while (fin>>p>>a>>b) wb.push_back({p,a,b});
}

for (auto [p,a,b]: wb) {
procs.push_back({p,a,b,b,-1,-1,a});
}

// Ready queues
vector<deque<int>> rq(quanta.size());

auto by_pid = [&](int pid)->Proc&{
for (auto &x: procs) if (x.pid==pid) return x; throw runtime_error("pid"); };

auto all_done = [&](){ for (auto &x: procs) if (x.remaining>0) return false; return true; };

// Events and stats
vector<Event> timeline;
map<int,int> current_q; // pid->queue index (where it currently resides)

int t = 0; // current time
int last_pid = -1, last_q = -1; // for compact Gantt segments

auto enqueue = [&](int pid, int q){
q = max(0, min(q, (int)quanta.size()-1));
rq[q].push_back(pid);
by_pid(pid).last_enq = t;
current_q[pid] = q;
};

auto arrivals = [&](){
}