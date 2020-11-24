// Your name here

// DEFINE YOUR FUNCTIONS HERE
// They have to be declared in the "headers.h" file.
//
// You *have* to use these 2 functions (already declared in records.cpp),
// but you may add other functions in here as well, if you want.
// See hint in the lab description document.

void InitializeStructures(UndergradStudents us[], int &size) {
  int i =0;
  while(us[i].Firstname != "X" || (i < 20)){
    cout << "Enter first name for student " << i+1 << " (or X to quit): ";
    getline(cin,us[i].FirstName);
    cout << "\nEnter last name for student " << i+1 << ": ";
    getline(cin,us[i].LastName);
    cout << "\nEnter major for student " << i+1 << ": ";
    cin >> us[i].Major;
    cout << "\nEnter GPA year 1 for student " << i+1 << ": ";
    cin >> us[i].GPA1;
    cout << "\nEnter GPA year 2 for student " << i+1 << ": ";
    cin >> us[i].GPA2;
    cout << "\nEnter GPA year 3 for student " << i+1 << ": ";
    cin >> us[i].GPA3;
    cout << "\nEnter GPA year 4 for student " << i+1 << ": ";
    cin >> us[i].GPA4;
    i++;
  }
  size = i;    
}


void SortUndergradStudents(UndergradStudents us[], int size){
  for(int x = 0 ; x < size; x++){
    for( int j= 0; j < size; j++){
      if(us[i].LastName[0] < us[j].LastName[0]){
	string first = us[i].LastName;
	us[i].LastName = us[j].LastName;
	us[j].LastName = first;
      }
    }
  }
}












void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
  cout << "\nThese are the sorted results:" << endl;
  SortUndergradStudents(us[], size);
}
