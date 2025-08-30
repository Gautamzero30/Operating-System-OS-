#include <bits/stdc++.h>
using namespace std;

// Process structure
struct Process {
    int pid;
    int nice;         // priority (default 0, range: -20 to 19)
    double weight;    // weight derived from nice value
    double vruntime;  // virtual runtime

    Process(int id, int n) {
        pid = id;
        nice = n;
        // Map nice → weight (simplified version)
        weight = 1024.0 / pow(1.25, nice); 
        vruntime = 0.0;
    }

    // Ordering by vruntime for CFS
    bool operator<(const Process& other) const {
        if (vruntime == other.vruntime) return pid < other.pid;
        return vruntime < other.vruntime;
    }
};

int main() {
    // Simulate 3 processes
    vector<Process> processes = {
        Process(1, 0),   // normal priority
        Process(2, 5),   // lower priority
        Process(3, -5)   // higher priority
    };

    // Red-Black tree (std::set)
    set<Process> runQueue(processes.begin(), processes.end());

    int totalTime = 20;   // simulate 20 units of CPU time
    int currentTime = 0;

    cout << "CFS Scheduling Simulation\n";
    cout << "---------------------------------\n";
    cout << "Time\tPID\tNice\tVruntime\n";

    while (currentTime < totalTime) {
        // Pick process with lowest vruntime
        auto it = runQueue.begin();
        Process current = *it;
        runQueue.erase(it);

        // Simulate running this process for 1 unit
        currentTime++;
        current.vruntime += 1.0 * (1024.0 / current.weight);

        // Reinsert into runQueue
        runQueue.insert(current);

        cout << currentTime << "\t" << current.pid 
             << "\t" << current.nice 
             << "\t" << fixed << setprecision(2) << current.vruntime << "\n";
    }

    return 0;
}
