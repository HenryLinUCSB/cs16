class AString {
  // You will need to declare:
  // 1. 2 constructors (see lab description for details)
  // 2. Three (3) member functions (see lab description for details)
  //      called getAString, cleanUp, countLetters
  //      one of which is a accessor function, and 2 are mutator functions
  // 3. One member variable called StringValue
  //
  // IMPORTANT: Figure out first which go in public and which in private.
public:
  
  AString();
  AString(string new);
  void getAString(); // Accessor because it is a "get"
  void cleanUp();
  void countLetters(string StringValue);
private:
  string StringValue;
  
};

// Declare the program function used in the main routine called compareCounts here:
// type compareCounts(arguments);
bool compareCounts(int ca1[], int ca2[]);
