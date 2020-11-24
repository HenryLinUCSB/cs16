// Your name here
// Henry Lin
// DEFINE YOUR FUNCTIONS HERE
void InitializeStructures(UndergradStudents us[], int &size);
void SortUndergradStudents(UndergradStudents us[], int size);
void WriteResults(ofstream &outf, UndergradStudents us[], int size);
// They have to be declared in the "headers.h" file.
//
// You *have* to use these 2 functions (already declared in records.cpp),
// but you may add other functions in here as well, if you want.
// See hint in the lab description document.

void InitializeStructures(UndergradStudents us[], int &size) {
  size = 0;
  int i = 0;
  int x = 1;
  // asks user for input, if he enters X the system quits or if # of students exceeds 20
  while(x == 1 && size < 20){
    cout << "Enter first name for student " << i + 1 << " (or X to quit): ";
    getline(cin,us[i].FirstName);
    if(us[i].FirstName == "X"){
      x = 0;
      break;
    }
    else{
      cout << "Enter last name for student " << i+1 << ": ";
      getline(cin,us[i].LastName);
      cout << "Enter major for student " << i+1 << ": ";
      cin >> us[i].Major;
      cout << "Enter GPA year 1 for student " << i+1 << ": ";
      cin >> us[i].GPA1;
      cout << "Enter GPA year 2 for student " << i+1 << ": ";
      cin >> us[i].GPA2;
      cout << "Enter GPA year 3 for student " << i+1 << ": ";
      cin >> us[i].GPA3;
      cout << "Enter GPA year 4 for student " << i+1 << ": ";
      cin >> us[i].GPA4;
      us[i].ID = i+1;
      us[i].avg =(us[i].GPA1 + us[i].GPA2 + us[i].GPA3 + us[i].GPA4)/4.00;
      cout << endl << endl;
      i++;
      size++;
    }
  }
}

void SortUndergradStudents(UndergradStudents us[], int size){
  string first;
  double num;
  //bubble sorting everything since the GPA first name etc. much follow the last name too
  for(int x = 0 ; x < size; x++){
    for( int j= 0; j < size; j++){
      if(us[x].LastName[0] < us[j].LastName[0]){
	first = us[x].LastName;
	us[x].LastName = us[j].LastName;
	us[j].LastName = first;

	first = us[x].FirstName;
	us[x].FirstName = us[j].FirstName;
	us[j].FirstName = first;

	first = us[x].Major;
	us[x].Major = us[j].Major;
	us[j].Major = first;

	num = us[x].GPA1;
	us[x].GPA1 = us[j].GPA1;
	us[j].GPA1 = num;

	num = us[x].GPA2;
	us[x].GPA2 = us[j].GPA2;
	us[j].GPA2 = num;

	num = us[x].GPA3;
	us[x].GPA3 = us[j].GPA3;
	us[j].GPA3 = num;

	num = us[x].GPA4;
	us[x].GPA4 = us[j].GPA4;
	us[j].GPA4 = num;
	
	
      }
    }
  }
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size) {
  // outputting the results into Results.txt with 2 decimal points.
  outf.open("Results.txt");
  outf << "\nThese are the sorted results:" << endl;
  outf.setf(ios::fixed);
  outf.setf(ios::showpoint);
  outf.precision(2);
  for(int i=0; i<size; i++){
    outf << "ID# " << us[i].ID << ". " << us[i].LastName << ", " << us[i].FirstName << ", " << us[i].Major << ", Average GPA: " << us[i].avg << endl;
  }
  outf.close();
}

