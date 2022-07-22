#include "tinbes.h"

#define TABLE_SIZE 25
#define RUNNING 'r'
#define PAUSED 'p'

// Process table: arrays of names, ids, states and addresses
string processName[TABLE_SIZE];
int id[TABLE_SIZE];
char state[TABLE_SIZE];
long addr[TABLE_SIZE];
int noOfProcesses = 0;
int idCounter = 0;

// Add new entry to end of process table with state 'RUNNING'
int newProcess(string name, long address) {

  
    id[noOfProcesses] = noOfProcesses + 1;
    processName[noOfProcesses] = name;
    addr[noOfProcesses] = address;
    state[noOfProcesses] = RUNNING;
    

  
  noOfProcesses++;
  return idCounter++;
}

// Remove entry from process table
void removeProcess(int i) {
  noOfProcesses--;
  for (int j = i; j < noOfProcesses; j++) {
    processName[j] = processName[j + 1];
    id[j] = id[j + 1];
    state[j] = state[j + 1];
    addr[j] = addr[j + 1];
  }
}


void executeProcesses() {
  long newAddr;
  for (int i = 0; i < noOfProcesses; i++) {
    if (state[i] == RUNNING) {

       
        newAddr = execute(addr[i]);
     
//        cout << "Process \""  <<  processName[i]  << "\" running"  << endl;
        
    


      if (newAddr == -1) {
        cout << "Process \"" << processName[i] << "\" has terminated." << endl;
        removeProcess(i--);
      } else {
        addr[i] = newAddr;
      }
    }
  }
}




void listProcesses() {
  for (int i = 0; i < noOfProcesses; i++) {
    cout << id[i] << ' ' << processName[i] << ' ' << state[i] << endl;
  }
}

int findProcess(int i) {
  for (int j = 0; j < noOfProcesses; j++) {
    if (id[j] == i) return j;
  }
  return -1;
}

void suspendProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == PAUSED) {
    cout << "Process already paused." << endl;
  }
  else { // set state to 'PAUSED'

    
      state[i] = PAUSED;
  

  }
}

void resumeProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
    return;
  }
  if (state[j] == RUNNING) {
    cout << "Process already running." << endl;
  }
  else { // set state to 'RUNNING'

    
      state[i] = RUNNING;
  

  }
}

void killProcess(int i) {
  int j = findProcess(i);
  if (j == -1) {
    cout << "Process does not exist." << endl;
  } else { // remove process from process table
    
    
      suspendProcess(i);
      removeProcess(i);
  
    
  }
}

int main() {
  unblockCin();
  string command;
  while (true) {
    if (charactersAvailable()) {
      command = readLine();
      if (command == "RUN") {
        string name = readLine();
        long address = stoi(readLine());
        cout << newProcess(name, address) << endl;
      }
      if (command == "LIST") {
        listProcesses();
       
      }
      if (command == "SUSPEND") {
        int i = stoi(readLine());
        suspendProcess(i);
      }
      if (command == "RESUME") {
        int i = stoi(readLine());
        resumeProcess(i);
      }
      if (command == "KILL") {
        int i = stoi(readLine());
        killProcess(i);
      }
    }
    else {
      executeProcesses();
    }
  }
}

