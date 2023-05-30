#include <bits/stdc++.h>
using namespace std ;
#define pb push_back 

///////////////"Helper functions"////////////////


int ReadInt(int high){
	cout << "\nEnter number in range " << 1 << " _ "<< high <<": ";
	int value ;
	cin >> value ;
	if (value>=1 and value <=high) return value ;


	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(high);
}



int ShowMenu(const vector <string>&vec){
    
	cout << "\nMenu:\n" ;
	for ( int i=0 ;i < (int)vec.size() ;i++){
		cout << "\t" << i+1 << " : " << vec[i] << "\n" ;
	}
	return ReadInt(vec.size()) ;
}






void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (const auto &line : lines)
		file_handler << line << "\n";

	file_handler.close();
}



int ToInt(const string &str){
    
    istringstream number(str) ; 
    
    int num ;
    number>>num ;

    return num ;
}

vector<string> ReadFileLines (string path){
    vector<string> lines ;

    fstream file_handler(path.c_str()) ;

    if(file_handler.fail()){
		 cout << path<<"\n0 ;0"
;        cout << "\n\nERROR: Can't Open The File\n\n"  ;
     return lines ;

    }
    string line ;
    while(getline(file_handler, line)){
        if(line.size()==0) continue;
        lines.push_back(line) ;
    }
    file_handler.close() ;
    return lines ;
}

vector<string> SplitString( string str){
  
    vector <string> substrs ;

     int first_pos {0} ;
      
       while((first_pos=(int)str.find(","))!=-1){
             substrs.pb(str.substr(0,first_pos));
             str.erase(0,first_pos+1) ;
       }
       substrs.pb(str) ;
       return substrs;


  
}

//////////////////////////////////////////////////////////////////////////



// for one question
class Question{
    private : 
       int question_id ; 
       /*
       parent_question_id to support thread .
       each question has a parent question  if the parent quesiton is -1 
       means that this is the first question in the thread 
       */
       int parent_question_id ;
       int from_user_id ;
       int to_user_id ;
       string question_text ;  
       /*
       if answer_text empty => this question not answered yet
       */
       string answer_text; 
       
       /* 
       to support anonymous qusetion 
       0 not anonymous 
       1 anonymous 
       */
       int is_anonymous_question ; 
   
     public :
      
      Question():
      question_id(-1) , parent_question_id(-1) , from_user_id(-1),to_user_id(-1)
      ,is_anonymous_question(-1) {
     
      }

      Question ( const string &line){ 
        vector<string > substrs = SplitString(line) ;
        assert(substrs.size()==7) ; // substrs should be contain 7 strings 
      

       question_id = ToInt(substrs[0]) ;
       parent_question_id =ToInt(substrs[1]) ;
       from_user_id = ToInt(substrs[2]) ;
       to_user_id = ToInt(substrs[3]) ; 
       is_anonymous_question = ToInt(substrs[4]) ;
       question_text = substrs[5] ;
        answer_text = substrs[6] ;
     
      }

      // to return string continue the data member separated with a semicolon
      string ReturnString()const{
        ostringstream oss ;
        oss<<question_id<<","<<parent_question_id<<","<<from_user_id<<","<<to_user_id
        <<","<<is_anonymous_question<<","<<question_text << "," << answer_text ;
    return oss.str() ;
      }

     void PrintQuestionToUser()const{
        string pattern {""} ;
        if(parent_question_id!=-1)
        pattern ="\tThread : "  ;
         
         cout << pattern << "Question Id {"<< question_id <<"}"  ;
         if(!is_anonymous_question){
          cout << " question from user id {" << from_user_id<<"}" ;
}
          cout << "\n Question: "<< question_text<<"\n" ;
          if(answer_text!=""){
          cout << pattern<<"\tAnswer : " << answer_text <<"\n" ;}
          cout << "\n" ;
     }
  
   void PrintQuestionFromUser() const{
              cout << "Question Id {" << question_id<<"}" ;
              if(!is_anonymous_question)
                cout << " this is not anonymous question" ;

                cout << " to user id {"<< to_user_id<<"}\n";

                cout << "your question is : " << question_text <<"\n" ;

                if(answer_text!="" ) 
                   cout << "the answer of this question: "<< answer_text <<"\n" ;
                   else 
                       cout << "\t Not Answered Yet \n" ;

   }

    void PrintFeedQuestion() const{
        if(parent_question_id!=-1)
         cout << "Thread Parent Question id{" << parent_question_id<<"}" ;
          else cout << " First Question in the thread it's Id {"<< question_id<<"}";

          if(!is_anonymous_question)
           cout << "from user id {"<< from_user_id<<"}" ;

           cout << " to user id {"<< to_user_id<<"}";

           cout <<"\n Question :" << question_text <<"\n";
           if(answer_text!="")
            cout << "\tAnswer :" << answer_text << "\n" ;  
          else cout <<"Not Answered Yet\n" ;
    }
  
  /////////////"Setters & Getters"/////////////

   const string& GetAnswerText() const {
		return answer_text;
	}

    void SetAnswerText(const string& answerText) {
		answer_text = answerText;
	}
     
    int GetFromUserId() const {
		return from_user_id;
	}

   void SetFromUserId(int fromUserId) {
		from_user_id = fromUserId;
	}

    int GetIsAnonymousQuestions() const {
		return is_anonymous_question;
	}

    void SetIsAnonymousQuestions(int isAnonymousQuestions) {
		is_anonymous_question = isAnonymousQuestions;
	}

    int GetParentQuestionId() const {
		return parent_question_id;
	}

    void SetParentQuestionId(int parentQuestionId) {
		parent_question_id = parentQuestionId;
	}

    int GetQuestionId() const {
		return question_id;
	}
  
    void SetQuestionId(int questionId) {
		question_id = questionId;
	}

    const string& GetQuestionText() const {
		return question_text;
	}

    void SetQuestionText(const string& questionText) {
		question_text = questionText;
	}
  
    int GetToUserId() const {
		return to_user_id;
	}

     void SetToUserId(int toUserId) {
		to_user_id = toUserId;
	}


};

// for one user
class User{
  private :
    int user_id;		// internal system ID
	string user_name;
	string password;
	string name;
	string email;
	int allow_anonymous_questions;	// 0 or 1
  
     vector<int> questions_id_from_user; // question From user
	// From question id to list of questions IDS on this question (thread questions) - For this user
	map<int, vector<int>> questionid_questionidsThead_to_map;

   public :
    
    //by defult string is empty 
     User() :
			user_id(-1), allow_anonymous_questions(-1) {
	}

     User(const string &line) {
		vector<string> substrs = SplitString(line);
		assert(substrs.size() == 6);

		user_id = ToInt(substrs[0]);
		user_name = substrs[1];
		password = substrs[2];
		name = substrs[3];
		email = substrs[4];
		allow_anonymous_questions = ToInt(substrs[5]);
	}
     
     //returning a string continue the data mempers separated with a semicolon
    string ReturnString() const {
		ostringstream oss;
		oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << allow_anonymous_questions;

		return oss.str();
	}
 
    void Print() const {
		cout << "User " << user_id << ", " << user_name << " " << password << ", " << name << ", " << email << "\n";
	}
 
   void ResetQuestionFromUesr(const vector <int> &From_questions){
    questions_id_from_user.clear() ;
 
   for( const auto & question_id:From_questions)
   questions_id_from_user.pb(question_id) ;

   }
   
    void ResetQuestionToUser(const vector<pair<int,int>> &to_questoins){
         
         questionid_questionidsThead_to_map.clear() ;
         for (const auto & id_pair : to_questoins)
			questionid_questionidsThead_to_map[id_pair.first].push_back(id_pair.second);
	
    }

    void ReadUser(const string &user_name,int id ){
           SetUserName(user_name);
	    	SetUserId(id);   
              
              string str;

		cout << "Enter password: without (spaces and semicolon) ";
		cin >> str;
		SetPassword(str);

		cout << "Enter name: without (spaces and semicolon) ";
		cin >> str;
		SetName(str);

		cout << "Enter email: without (spaces and semicolon)";
		cin >> str;
		SetEmail(str);

		cout << "Allow anonymous questions? (0 or 1): ";
		int st;
		cin >> st;
		SetAllowAnonymousQuestions(st);
    }

  //////////////"Setters & Getters"//////////////
   int IsAllowAnonymousQuestions() const {
		return allow_anonymous_questions;
	}

	void SetAllowAnonymousQuestions(int allowAnonymousQuestions) {
		allow_anonymous_questions = allowAnonymousQuestions;
	}

	const string& GetEmail() const {
		return email;
	}

	void SetEmail(const string& email) {
		this->email = email;
	}

	const string& GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	const string& GetPassword() const {
		return password;
	}

	void SetPassword(const string& password) {
		this->password = password;
	}

	int GetUserId() const {
		return user_id;
	}

	void SetUserId(int userId) {
		user_id = userId;
	}

	const string& GetUserName() const {
		return user_name;
	}

	void SetUserName(const string& userName) {
		user_name = userName;
	}

	const map<int, vector<int> >& GetQuestionidQuestionidsTheadToMap() const {
		return questionid_questionidsThead_to_map;
		// Note no setter is provided / returned as const &
	}

	const vector<int>& GetQuestionsIdFromMe() const {
		return questions_id_from_user;
		// Note no setter is provided
	}

};

// For all questoins
class QuestionsManager{
    private:
	// From question id to list of questions IDS on this question (thread questions) - All users
	map<int, vector<int>> questionid_questionidsThead_to_map;

	// Map the question id to question object. Let's keep one place ONLY with the object
	// When you study pointers, easier handling
	map<int, Question> questionid_questionobject_map;

	int last_id;

public:
	QuestionsManager() {
		last_id = 0;
	}

   void LoadDatabase(){
    last_id =0 ;
    questionid_questionidsThead_to_map.clear() ;
    questionid_questionobject_map.clear() ;
     
      vector<string>lines =ReadFileLines("C:\\Users\\omarm\\OneDrive\\Desktop\\ps\\totalquestions.txt") ;

      for (  auto &line:lines) {
        Question question(line) ; // create the data mempers 
       last_id=max(last_id,question.GetQuestionId()) ;
    
    questionid_questionobject_map[question.GetQuestionId()] = question ;

    if(question.GetParentQuestionId ()==-1)
    questionid_questionidsThead_to_map[question.GetQuestionId()].pb(question.GetQuestionId()) ;
    else questionid_questionidsThead_to_map [question.GetParentQuestionId()].pb(question.GetQuestionId()) ;

      }

   }

  vector <int> GetQuestionsFromUser(const User &user) const{
      vector<int> questions_id ;
       
      for (const auto &i:questionid_questionobject_map){
         const Question &q =i.second ;
         if (q.GetFromUserId() == user.GetUserId()) 
         questions_id .pb(q.GetQuestionId()) ;
      }

     return questions_id ;

  }
   
   vector<pair< int,int>> GetQuestionsToUser(const User & user)const{
    vector<pair<int,int>> questions_id ;

     for (const auto & i: questionid_questionobject_map){
         
          const Question & q =i.second ;
          if(q.GetToUserId()==user.GetUserId()){
  
          if(q.GetParentQuestionId()==-1) 
          questions_id.pb(make_pair(q.GetQuestionId(),q.GetQuestionId())) ;
          else questions_id.pb(make_pair(q.GetParentQuestionId(),q.GetQuestionId())) ;
          
           }
     }
     return questions_id ;
   }

   void PrintUserToQuestions(const User &user) const {
		cout << "\n";

		if (user.GetQuestionidQuestionidsTheadToMap().size() == 0)
			cout << "No Questions";

		for (const auto &pair : user.GetQuestionidQuestionidsTheadToMap()) {		// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				// Accessing questionid_questionobject_map[] change the map by adding if not exist. You can't use in const function
				// Here we just find, which return iterator (second is like a pointer to object)
				const Question &question = questionid_questionobject_map.find(question_id)->second;
				question.PrintQuestionToUser();
			}
		}
		cout << "\n";
	}
 
   
	void PrintUserFromQuestions(const User &user) const {
		cout << "\n";
		if (user.GetQuestionsIdFromMe().size() == 0)
			cout << "No Questions";

		for (const auto &question_id : user.GetQuestionsIdFromMe()) {		//  vector<Question>
			const Question &question = questionid_questionobject_map.find(question_id)->second ;
           
			question.PrintQuestionFromUser();
		}
		cout << "\n";
	}
   
    // Used in Answering a question for YOU.
	// It can be any of your questions (thread or not)
	int ReadQuestionIdAny(const User &user) const {
		int question_id;
		cout << "Enter Question id or -1 to cancel: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!questionid_questionobject_map.count(question_id)) {
			cout << "\nERROR: No question with such ID. Try again\n\n";
			return ReadQuestionIdAny(user);
		}
		const Question &question = questionid_questionobject_map.find(question_id)->second;

		if (question.GetToUserId() != user.GetUserId()) {
			cout << "\nERROR: this question doesn't for you please try again\n\n";
			return ReadQuestionIdAny(user);
		}
		return question_id;
	}

   // Used to ask a question on a specific thread for whatever user
	int ReadQuestionIdThread(const User &user) const {
		int question_id;
		cout << "For thread question: Enter Question id or -1 for new question: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!questionid_questionidsThead_to_map.count(question_id)) {
			cout << "No thread question with such ID. Try again\n";
			return ReadQuestionIdThread(user);
		}
		return question_id;
	}
    
    void AnswerQuestion(const User &user) {
		int question_id = ReadQuestionIdAny(user);

		if (question_id == -1)
			return;

		Question &question = questionid_questionobject_map[question_id];

		question.PrintQuestionToUser();

		if (question.GetAnswerText() != "")
			cout << "\nWarning: Already answered. Answer will be updated\n";

		cout << "Enter answer: ";	// if user entered comma, system fails :)

		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetAnswerText(line);
	}
             
    void DeleteQuestion(const User &user) {
		int question_id = ReadQuestionIdAny(user);

		if (question_id == -1)
			return;

		vector<int> ids_to_remove;	// to remove from questionid_questionobject_map

		// Let's see if thread or not. If thread, remove all of it
		if (questionid_questionidsThead_to_map.count(question_id)) { // thread
			ids_to_remove = questionid_questionidsThead_to_map[question_id];
			questionid_questionidsThead_to_map.erase(question_id);
		} else {
			ids_to_remove.push_back(question_id);

			// let's find in which thread to remove. Consistency is important when have multi-view
			for (auto &pair : questionid_questionidsThead_to_map) {
				vector<int> &vec = pair.second; // & when delete the element in vec it will reflect to the map
				for (int pos = 0; pos < (int) vec.size(); ++pos) {
					if (question_id == vec[pos]) {
						vec.erase(vec.begin() + pos);
						break;
					}
				}
			}
		}
		for (const auto &id : ids_to_remove)
			questionid_questionobject_map.erase(id);
	}



void AskQuestion(const User &user, const pair<int, int> &to_user_pair) {
		Question question;

		if (!to_user_pair.second) {
			cout << "Note: Anonymous questions are not allowed for this user\n";
			question.SetIsAnonymousQuestions(0);
		} else {
			cout << "Is anonymous questions?: (0 or 1): ";
			int st;
			cin >> st;
			question.SetIsAnonymousQuestions(st);
		}

		question.SetParentQuestionId(ReadQuestionIdThread(user));

		cout << "Enter question text: ";	// if user entered comma, system fails :)
		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetQuestionText(line);

		question.SetFromUserId(user.GetUserId());
		question.SetToUserId(to_user_pair.first);

		// What happens in 2 parallel sessions who asked question?
		// They are given same id. This is wrong handling :)
		question.SetQuestionId(++last_id);

		questionid_questionobject_map[question.GetQuestionId()] = question;

		if (question.GetParentQuestionId() == -1)
			questionid_questionidsThead_to_map[question.GetQuestionId()].push_back(question.GetQuestionId());
		else
			questionid_questionidsThead_to_map[question.GetParentQuestionId()].push_back(question.GetQuestionId());
	}



  void ListFeed() const {
		for (const auto &pair : questionid_questionobject_map) {
			const Question &question = pair.second;

			if (question.GetAnswerText() == "")
				continue;
			question.PrintFeedQuestion();
		}
	}

	void UpdateDatabase() {
		vector<string> lines;

		for (const auto &pair : questionid_questionobject_map)
			lines.push_back(pair.second.ReturnString());
		WriteFileLines("C:\\Users\\omarm\\OneDrive\\Desktop\\ps\\totalquestions.txt", lines, false);
	}







} ;

// for all users 

class UsersManager{
	private : 
	map <string ,User> username_userobject_map ;
	User current_user ;
	int last_id ;

	public:
	UsersManager() : last_id(0){} 
	
	void LoadDatabase(){
		last_id =0 ;
		username_userobject_map.clear() ;
		string file {"C:\\Users\\omarm\\OneDrive\\Desktop\\ps\\username.txt"} ;
		vector <string> lines= ReadFileLines(file) ;
		for (const auto &i:lines){
			User user (i) ;
			username_userobject_map [user.GetUserName()]= user ;
			last_id = max (last_id , user.GetUserId()) ;
		}
	}
  
   void StartSystem(){
	int choice = ShowMenu({"Login" ,"Sign Up"}) ;
	if(choice==1) DoLogin() ;
	else DoSignUp() ;
   }

   void DoLogin(){
	LoadDatabase();

	 while (true)
	 {
		string name , pass ;
		 cout << "enter user name & password: ";
		  cin >> name >> pass ;
		  current_user.SetUserName (name) ;
		  current_user.SetPassword (pass) ;
		  if(!username_userobject_map.count(current_user.GetUserName())) 
		  {
			cout << "\nInvalid user name  Try again\n\n";
				continue;
		  }
		  const User & user = username_userobject_map[current_user.GetUserName()] ; 
	     if (current_user.GetPassword()!=user.GetPassword()){
			cout << "\nInvalid password. Try again\n\n";
				continue;
		 }

		 current_user = user ;
		 break;

	 }
	 
   }

   void DoSignUp(){
	string user_name ;
	while(true){
		cout << "Enter user name. ( without spaces): ";
		cin >> user_name; 
		if (username_userobject_map.count(user_name)) {
			 cout << "Already used. Try again\n" ;
			  continue; 
		} 
		 else break; 
   	}
	current_user.ReadUser(user_name,++last_id);
    username_userobject_map[current_user.GetUserName()] = current_user ;
	UpdateDatabase(current_user) ;

   }
   
    void UpdateDatabase(const User &user) {
		string line = user.ReturnString();
		vector<string> lines(1, line);
		WriteFileLines("C:\\Users\\omarm\\OneDrive\\Desktop\\ps\\username.txt", lines);
	}
   
   void ResetQuestionsFromUser(const vector <int> &to_questoins){
	current_user.ResetQuestionFromUesr(to_questoins) ;
   }
   void ResetQuestionsToUser(const vector <pair<int,int>> &to_questoins){
	current_user.ResetQuestionToUser(to_questoins) ;
   }

   void ListUsersNanmesIds() const{
	 for (const auto&i:username_userobject_map) {
			cout << "ID: " << i.second.GetUserId() << "\t\tName: " << i.second.GetName() << "\n";
	 }
   }

    pair < int ,int > ReadUserId() const {
		int user_id ;
		cout << "Enter User id or -1 to cancel: "; 
	   
	   cin >> user_id ;

	   if(user_id ==-1)  return make_pair(-1,-1) ;

	   for (const auto &pair : username_userobject_map) {
		if(pair.second.GetUserId()==user_id)
		return make_pair(user_id, pair.second .IsAllowAnonymousQuestions()) ;

	   }
	   cout << "Invalid user id. please try again\n" ;
	   return ReadUserId() ;
	}

	const User&GetcurrentUser() const {
		 return current_user ;

	}




} ;



// the system 
class AskMeSystem{
	private :
	 UsersManager users_manager;
	 QuestionsManager questions_manager ;

	 void LoadDatabase(bool fill_user_questions = false){
		users_manager.LoadDatabase() ;
		questions_manager.LoadDatabase () ;

		if(fill_user_questions) 
		ResetCurrentUserQuestions() ;
	 }
	 void ResetCurrentUserQuestions() {
		const User& user = users_manager.GetcurrentUser();

		const auto &to_questions = questions_manager.GetQuestionsFromUser(user);
		users_manager.ResetQuestionsFromUser(to_questions);

		const auto &from_questions = questions_manager.GetQuestionsToUser(user);
		users_manager.ResetQuestionsToUser(from_questions);
	} 

	
public:
	void Run() {	// only public one
		LoadDatabase(false);
		users_manager.StartSystem();
		ResetCurrentUserQuestions();

		vector<string> menu;
		menu.push_back("Print Questions To Me");
		menu.push_back("Print Questions From Me");
		menu.push_back("Answer Question");
		menu.push_back("Delete Question");
		menu.push_back("Ask Question");
		menu.push_back("List System Users");
		menu.push_back("Feed");
		menu.push_back("Logout");
		
		
		
		while (true) {
			int choice = ShowMenu(menu);
			LoadDatabase(true);

			if (choice == 1)
				questions_manager.PrintUserToQuestions(users_manager.GetcurrentUser());
			else if (choice == 2)
				questions_manager.PrintUserFromQuestions(users_manager.GetcurrentUser());
			else if (choice == 3) {
				questions_manager.AnswerQuestion(users_manager.GetcurrentUser());
				questions_manager.UpdateDatabase();
			} else if (choice == 4) {
				questions_manager.DeleteQuestion(users_manager.GetcurrentUser());
				// Let's build again (just easier, but slow)
				ResetCurrentUserQuestions();
				questions_manager.UpdateDatabase();
			} else if (choice == 5) {
				pair<int, int> to_user_pair = users_manager.ReadUserId();
				if (to_user_pair.first != -1) {
					questions_manager.AskQuestion(users_manager.GetcurrentUser(), to_user_pair);
					questions_manager.UpdateDatabase();
				}
			} else if (choice == 6)
				users_manager.ListUsersNanmesIds();
			else if (choice == 7)
				questions_manager.ListFeed();
			else
				break;
		}
		Run();	// Restart again
	}


} ;



int main() {
	
	AskMeSystem service;
	service.Run();

	return 0;
}


