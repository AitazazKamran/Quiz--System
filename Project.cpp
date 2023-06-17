//============================================================================
// Name        : Project.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <random>
#include <ctime>
#include <algorithm>
#include <chrono> // for high_resolution_clock
#include <thread> // for sleep_for
#include<iomanip>
#include <stdexcept> // the invalid_argument

using namespace std;

class User
{
	string id;
	string name;
	string password;

public:
	string getid()
	{
		return id;
	}
	void setid(string a)
	{
		id = a;
	}
	void setname(string n)
	{
		name = n;
	}
	string getname()
	{
		return name;
	}
};
class Quiz
{

	int noQuestions;
	string maxtime;
	string starttime;
	string endtime;
	int totalMarks, markspq;

public:
	Quiz(){};
	Quiz(int noq, int mt, string st, string et)
	{
		noQuestions = noq;
		maxtime = mt;
		starttime = st;
		endtime = et;
	}
	int getTotalMarks() const
	{
		return totalMarks;
	}

	void setTotalMarks(int noq)
	{
		totalMarks = noq;
	}
	int getMarksPQ() const
	{
		return markspq;
	}

	void setMarksPQ(int noq)
	{
		markspq = noq;
	}

	int getNoQuestions() const
	{
		return noQuestions;
	}

	void setNoQuestions(int noq)
	{
		noQuestions = noq;
	}

	string getMaxTime() const
	{
		return maxtime;
	}

	void setMaxTime(string mt)
	{
		maxtime = mt;
	}

	string getStartTime() const
	{
		return starttime;
	}

	void setStartTime(string st)
	{
		starttime = st;
	}

	string getEndTime() const
	{
		return endtime;
	}

	void setEndTime(string et)
	{
		endtime = et;
	}
};
class Question
{
public:
	string questions;
	string options;
	string answers;
	string courseid;
	int questiontype;
	string questiontypes;
	string topic = "pakistan";
	// addquestion();

	int setquestions(Quiz &quiz, string course)

	{

		if (course == "CS 101")
		{
			courseid = "Programming Fundamentals";
		}
		else if (course == "CS 301")
		{
			courseid = "Data Structures";
		}
		else if (course == "CS 102")
		{
			courseid = "Introduction To Computing";
		}
		else if (course == "CS 302")
		{
			courseid = "Analysis of Algorithms";
		}
		else if (course == "SE 301")
		{
			courseid = "Software Requirements Engineering";
		}
		else if (course == "CS 407")
		{
			courseid = "Big Data Analytics";
		}
		else if (course == "CS 307")
		{
			courseid = "Artificial Intelligence";
		}
		else if (course == "CS 601")
		{
			courseid = "Deep Learning";
		}
		else if (course == "CS 501")
		{
			courseid = "Research Methodology";
		}
		else if (course == "CS 409")
		{
			courseid = "Digital Image Processing";
		}
		else if (course == "CS 201")
		{
			courseid = "Object Oriented Programming";
		}
	meu:
		string s1;
		cout << "what Question Type Do you want?\n"
			 << "1.MCQ's\n"
			 << "2.True/False\n"
			 << "3.long Questions\n";
		cin >> questiontype;
		cout << "Topic\n";
		cin >> topic;
		// getline(cin,topic);
		// cin.ignore();
		/*printf("From which Topic:\n");
			scanf("%99s", topic); // read up to 99 characters into the topic buffer
			getchar(); // consume the newline character left in the input stream

			printf("\n\ntopic\n\n%s\n\n", topic);*/
		string temp1, temp;
		temp1 = temp = courseid;
		ofstream csvFile(temp += ".csv");
		csvFile << ""; // write an empty string to the file
		csvFile.close();
		ifstream inFile("questions.csv");

		// Open the output CSV file
		ofstream outFile(temp1 += ".csv", std::ios::app);
		outFile << courseid << "," << topic << "," << quiz.getNoQuestions() << "," << quiz.getMaxTime() << ","
				<< quiz.getStartTime() << "," << quiz.getEndTime() << "," << quiz.getMarksPQ() << "," << quiz.getTotalMarks() << endl;

		// Read the input CSV file line by line
		string line;
		while (getline(inFile, line))
		{
			// Parse the line into fields

			stringstream ss(line);
			string course, type, question, option1, option2, option3, option4, answer;
			if (questiontype == 1)
			{
				getline(ss, type, ',');
				getline(ss, course, ',');
				getline(ss, question, ',');
				getline(ss, option1, ',');
				getline(ss, option2, ',');
				getline(ss, option3, ',');
				getline(ss, option4, ',');
				getline(ss, answer, ',');
				int typeInt;
				try
				{
					typeInt = stoi(type);
				}
				catch (const invalid_argument &e)
				{
					cerr << "Invalid type field: " << type << endl;
					continue;
				}

				// Check if this question should be copied
				bool shouldCopy = false;
				// cout<<"typeint="<<typeInt<<"\nquestiontype= "<<questiontype<<"\ncourse "<<course<<"\ncourseid "<<courseid;
				if (typeInt == questiontype && course == courseid)
					shouldCopy = 1;

				// cout<<"hello <<"<<shouldCopy<<endl;

				// If this question should be copied, write it to the output CSV file
				if (shouldCopy)
				{
					outFile << type << "," << course << "," << question << "," << option1 << ","
							<< option2 << "," << option3 << "," << option4 << "," << answer << endl;
				}
			}
			else if (questiontype == 2)
			{
				getline(ss, type, ',');
				getline(ss, course, ',');
				getline(ss, question, ',');
				getline(ss, answer, ',');
				int typeInt;
				try
				{
					typeInt = stoi(type);
				}
				catch (const invalid_argument &e)
				{
					cerr << "Invalid type field: " << type << endl;
					continue;
				}

				// Check if this question should be copied
				bool shouldCopy = false;
				// cout<<"typeint="<<typeInt<<"\nquestiontype= "<<questiontype<<"\ncourse "<<course<<"\ncourseid "<<courseid;
				if (typeInt == questiontype && course == courseid)
					shouldCopy = 1;

				// cout<<"hello <<"<<shouldCopy<<endl;

				// If this question should be copied, write it to the output CSV file
				if (shouldCopy)
				{
					outFile << type << "," << course << "," << question << "," << answer << endl;
				}
			}
			else if (questiontype == 3)
			{
				getline(ss, type, ',');
				getline(ss, course, ',');
				getline(ss, question, ',');
				int typeInt;
				try
				{
					typeInt = stoi(type);
				}
				catch (const invalid_argument &e)
				{
					cerr << "Invalid type field: " << type << endl;
					continue;
				}

				// Check if this question should be copied
				bool shouldCopy = false;
				// cout<<"typeint="<<typeInt<<"\nquestiontype= "<<questiontype<<"\ncourse "<<course<<"\ncourseid "<<courseid;
				if (typeInt == questiontype && course == courseid)
					shouldCopy = 1;

				// cout<<"hello <<"<<shouldCopy<<endl;

				// If this question should be copied, write it to the output CSV file
				if (shouldCopy)
				{
					outFile << type << "," << course << "," << question << endl;
				}
			}
		}

		// Close the input and output files
		inFile.close();
		outFile.close();
		int o;
		cout << "Quiz has been Generated\n";
		cout << "Do you want to recreate quiz\n1.Yes\n2.logout\n";
		cin >> o;
		if (o == 1)
		{
			goto meu;
		}
		else
			return 1;
	}
};
class Teacher : User
{
	string coursename;
	int questions;

public:
	int teacherMenu()
	{
	label:
		int y;
		cout << "1.Do you want to set Quiz\n";
		cout << "2.Check marks of  course \n";
		cout << "3.Edit Password\n";
		cout << "0.Exit\n";
		cin >> y;
		if (y == 0)
		{
			return 1;
		}
		else if (y == 3)
		{
			string assword;
			bool a = 0;
			bool b = 0;
			bool f = 0;
			bool d = 0;
			bool e = 0;
			// specify the user and new password
			while (1)
			{
				cout << "Type New Password \n";

				cin >> assword;
				if (assword.length() >= 6)
				{
					a = 1;
				}

				for (char c : assword)
				{
					if (isupper(c))
					{
						b = 1;
					}
					else if (islower(c))
					{
						f = 1;
					}
					else if (isdigit(c))
					{
						d = 1;
					}
					else if (ispunct(c))
					{
						e = 1;
					}
				}
				// cout<<a<<b<<c<<d<<e;
				if (a && b && f && d && e)
				{
					break;
				}
				else
				{
					cout << "password must contain Uppercase /Lowercase/special charcter/and digit/must be of more than 6 letters\n";
				}
			}

			// open the file for reading and writing
			ifstream file_in("teacher.csv");
			ofstream file_out("temp.csv");

			string line;
			while (getline(file_in, line))
			{
				stringstream ss(line);
				string name, password, course;
				getline(ss, name, ',');
				getline(ss, password, ',');
				getline(ss, course, ',');

				// if the row contains the user, update the password
				if (course == coursename)
				{
					password = assword;
				}

				// write the updated row to the temporary file
				file_out << name << "," << password << "," << course << endl;
			}

			// close the files
			file_in.close();
			file_out.close();
			string t = "teacher.csv";
			// rename the temporary file to the original file
			remove(t.c_str());
			rename("temp.csv", t.c_str());
		}
		else if (y != 1 && y != 2)
		{
			cout << "invalid input\n";
			goto label;
		}
		else if (y == 2)
		{
			ifstream file("marks.csv");
			string name, id, course, om, tm, line, cc;

			while (getline(file, line))
			{
				stringstream ss(line);
				getline(ss, name, ',');
				getline(ss, id, ',');
				getline(ss, course, ',');
				getline(ss, om, ',');
				getline(ss, tm, ',');

				if (course == "Programming Fundamentals")
				{
					cc = "CS 101";
				}
				else if (course =="Data Structures" )
				{
					cc = "CS 301";
				}
				else if (course == "Introduction To Computing")
				{
					cc = "CS 102";
				}
				else if (course =="CS 302")
				{
					cc =  "Analysis of Algorithms";
				}
				else if (course == "SE 301")
				{
					cc = "Software Requirements Engineering";
				}
				else if (course =="Big Data Analytics")
				{
					cc =  "CS 407";
				}
				else if (course =="Artificial Intelligence" )
				{
					cc = "CS 307";
				}
				else if (course =="Deep Learning" )
				{
					cc = "CS 601";
				}
				else if (course == "Research Methodology")
				{
					cc = "CS 501";
				}
				else if (course =="Digital Image Processing")
				{
				      cc =  "CS 409";
				}
				else if (course =="Object Oriented Programming")
				{
					cc =  "CS 201";
				}
				if (coursename==cc)
				{
					cout<<"Name "<<name<<" Obtained Marks"<<om<<" TotalMarks "<<tm<<endl;
				}
			}
		}

		else if (y == 1)
		{
			// Create a new Quiz object
			Quiz quiz;
			int noQuestions, Marksqs, tm;
			string maxtime, starttime, endtime;
			while (1)
			{
				cout << "Enter number of questions: ";
				cin >> noQuestions;
				if (noQuestions > 0 && noQuestions < 5)
					break;
				else
					cout << "No more Than 5 Questions can be added\n";
			}
			quiz.setNoQuestions(noQuestions);
			cout << "Enter maximum time (in Seconds): ";
			cin >> maxtime;
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard remaining characters in input stream

			quiz.setMaxTime(maxtime);
			cout << "Enter start time  (mm/dd/hr): ";
			getline(cin, starttime);
			quiz.setStartTime(starttime);
			cout << "Enter end time (mm/dd/hr): ";
			getline(cin, endtime);
			quiz.setEndTime(endtime);
			while (1)
			{
				cout << "Enter Marks for each question: ";
				cin >> Marksqs;
				cout << "Enter TotalMarks: ";
				cin >> tm;
				if (tm > Marksqs)
				{
					quiz.setMarksPQ(Marksqs);
					quiz.setTotalMarks(tm);
					break;
				}
			}
			Question q;
			if (q.setquestions(quiz, coursename))
				return 1;
			else
				return 0;
		}
		return 1;
	}

	Teacher(string n, string c)
	{
		setname(n);
		coursename = c;
	}
};
class Student : public User
{
	int courses[11];

public:
	void setcourses(int *array)
	{
		for (int i = 0; i < 11; i++)
		{
			courses[i] = array[i];
		}
	}
	int attemptquiz(string a)
	{
		string temp = a;
		ifstream infile(temp += ".csv");

		// Read the file line by line
		string line;
		int marks = 0;
		if (getline(infile, line))
		{
			// Create a stringstream to parse the line
			stringstream ss(line);

			// Read the fields separated by commas
			string courseid, topic, noQuestions, maxTime, startTime, endTime, mpq, totalmarks;
			getline(ss, courseid, ',');
			getline(ss, topic, ',');
			getline(ss, noQuestions, ',');
			getline(ss, maxTime, ',');
			getline(ss, startTime, ',');
			getline(ss, endTime, ',');
			getline(ss, mpq, ',');
			getline(ss, totalmarks, ',');
			// getline(ss, type);
			Quiz q;
			if (courseid == a)
			{
				q.setEndTime(endTime);
				q.setMaxTime(maxTime);
				q.setStartTime(startTime);
				q.setMarksPQ(stoi(mpq));
				q.setTotalMarks(stoi(totalmarks));

				cout << "For Course : " << courseid << "\nFrom Topic : " << topic << "\nTotal no. of Questions : " << noQuestions << "\nMaximum Time Available : " << maxTime << " seconds";
				cout << "\nStart Time :" << startTime << "\nEnd Time : " << endTime << endl
					 << "Total Marks : " << totalmarks << endl
					 << "Marks per Question : " << mpq << endl;

				string input;
				cout << "Press Enter to start Quiz ...";
				getline(std::cin, input);
				cin.ignore();

				infile.close();
			}
			else
			{
				cout << "There is no quiz available for this Course\n";
				return 1;
			}
			string temp1 = a;
			ifstream infile(temp1 += ".csv");
			if (!infile.is_open())
			{
				cout << "No Quiz Available for this Course " << endl;
			}
			int noq = stoi(noQuestions);
			Question qs[noq];
			int size = 0;
			string line;
			int count = 0;
			getline(infile, line); // discard first line
			while (getline(infile, line) && count < noq)
			{
				count++;
				Question q;
				string course, question, type, answer, options, sans;
				stringstream ss(line);
				getline(ss, type, ',');
				if (type == "1")
				{
					q.questiontype = 1;
					getline(ss, q.courseid, ',');
					getline(ss, q.questions, ',');
					getline(ss, q.options, ',');
					getline(ss, q.answers, ',');
					qs[size] = q;
					size++;
					/*cout << question << endl;
					cout << options << endl;
					cin >> sans;
					if (sans == answer)
					{
						marks++;
					}*/
				}

				else if (type == "2")
				{
					q.questiontype = 2;
					getline(ss, q.courseid, ',');
					getline(ss, q.questions, ',');
					getline(ss, q.answers, ',');
					/*cout << question << endl;
					cin >> sans;
					if (sans == answer)
					{
						marks++;
					}*/
					qs[size] = q;
					size++;
				}
				else if (type == "3")
				{
					q.questiontype = 3;
					getline(ss, q.courseid, ',');
					getline(ss, q.questions, ',');
					/*cout << question << endl;
					getline(cin, sans);
					cin.ignore();
					marks += (sans.length() * 0.5);*/
				}

				// cout << course << ": " << question << endl;
			}
			//		string courseid, topic, noQuestions, maxTime, startTime, endTime;

			shuffle_questions(qs, size);
			present_questions(qs, size, a, q);

			// cout << "marks " << marks << endl;
		}
		// Close the file
		infile.close();
		return 1;
	}
	void shuffle_questions(Question questions[], int size)
	{
		default_random_engine engine(time(nullptr));
		uniform_int_distribution<int> dist(0, size - 1);
		for (int i = 0; i < size; i++)
		{
			int j = dist(engine);
			swap(questions[i], questions[j]);
		}
	}
	void present_questions(Question questions[], int size, string course, Quiz &a)
	{
		int marks = 0;
		int TT = stoi(a.getMaxTime());

		if (questions[0].questiontype == 1)
		{ // Check if time limit has been reached
			auto start_time = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < size; i++)
			{
				auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
				if (elapsed_time >= TT)
				{
					cout << "Time's up! Quiz has ended." << endl;
					break;
				}
				const auto &q = questions[i];
				cout << q.questions << endl
					 << q.options << endl;
				string answer;
				getline(cin, answer);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				// cout << q.answers << endl;
				if (answer == q.answers)
				{
					marks += a.getMarksPQ();
				}
			}
		}
		else if (questions[0].questiontype == 2)
		{
			auto start_time = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < size; i++)

			{
				auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();

				// cout << elapsed_time << endl;
				if (elapsed_time >= TT)
				{
					cout << "Time's up! Quiz has ended." << endl;
					break;
				}
				const auto &q = questions[i];
				cout << "T Or F? \n";
				cout << q.questions << endl;
				string answer;
				getline(cin, answer);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (answer == q.answers)
				{
					marks += a.getMarksPQ();
				}
			}
		}
		else if (questions[0].questiontype == 3)
		{
			auto start_time = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < size; i++)
			{
				auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
				if (elapsed_time >= TT)
				{
					cout << "Time's up! Quiz has ended." << endl;
					break;
				}
				const auto &q = questions[i];
				cout << q.questions << endl;
				string answer;
				getline(cin, answer);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				marks += (answer.length() * 0.5);
			}
		}
		// cout << "Your marks are " << marks << endl;
		ofstream outfile("marks.csv", ios::app);

		outfile << getname() << "," << getid() << "," << course << "," << marks << "," << a.getTotalMarks() << endl;
		outfile.close();
		cout << "Your quiz is finished\n";
		string c = course;
		/*ofstream outfil(, ios::app);
		outfil << getname() << "," << getid() << "," << course << endl;
		outfil.close();*/
		ifstream file_in(c += "sheet.csv");
		ofstream file_out("temp.csv");

		string line;
		while (getline(file_in, line))
		{
			stringstream ss(line);
			string name, id, attendace;
			getline(ss, id, ',');
			getline(ss, name, ',');
			getline(ss, attendace, ',');

			// if the row contains the user, update the attendance
			if (name == getname())
			{
				attendace = "0";
			}

			// write the updated row to the temporary file
			file_out << id << "," << name << "," << attendace << endl;
		}

		// close the files
		file_in.close();
		file_out.close();
		string te = course;
		string t = te += "sheet.csv";
		// rename the temporary file to the original file
		remove(t.c_str());
		rename("temp.csv", t.c_str());
	}

	// viewmarks();
	int studentMenu()
	{
		int ch;
		string array[11] = {{"Programming Fundamentals"}, {"Object Oriented Programming"}, {"Introduction To Computing"}, {"Data Structures"}, {"Analysis of Algorithms"}, {"Software Requirements Engineering"}, {"Research Methodology"}, {"Big Data Analytics"}, {"Artificial Intelligence"}, {"Deep Learning"}, {"Digital Image Processing"}};
	label:
		cout << "1.View Results\n";
		cout << "2.Attempt Quiz\n";
		cout << "3.View attendace\n";
		cout << "4.Edit Password\n";
		cout << "5.LogOut\n";
		cin >> ch;
		if (ch == 1)
		{
			string line;
			ifstream infil("marks.csv"); // open the input file

			while (getline(infil, line))
			{
				stringstream ss(line);
				string name, rollno, course, marks, tm;

				getline(ss, name, ',');	  // get the name component
				getline(ss, rollno, ','); // get the roll number component
				getline(ss, course, ','); // get the course name component
				getline(ss, marks, ',');  // get the marks component
				getline(ss, tm, ',');
				if (name == getname())
				{
					cout << "Name: " << name << endl;
					cout << "Roll No: " << rollno << endl;
					cout << "Course: " << course << endl;
					cout << "Marks: " << marks << endl;
					cout << "Total Marks: " << tm << endl;
					cout << endl;
				}
			}

			infil.close();
			goto label;
		}
		else if (ch == 2)
		{
			cout << "For Which Course?\n";
			int cho;
			for (int i = 0; i < 11; i++)
			{
				if (courses[i])
					cout << i << "." << array[i] << endl;
			}
			cin >> cho;
			if (attemptquiz(array[cho]))
				goto label;
		}
		else if (ch == 3)
		{
			string line;
			ifstream infil("attendacesheet.csv"); // open the input file

			while (getline(infil, line))
			{
				stringstream ss(line);
				string name, rollno, course, marks;

				getline(ss, name, ',');	  // get the name component
				getline(ss, rollno, ','); // get the roll number component
				getline(ss, course, ','); // get the course name component

				if (name == getname())
				{

					cout << "Present in : " << course << endl;

					cout << endl;
				}
			}

			infil.close();
			goto label;
		}
		else if (ch == 4)
		{
			cout << "Type 4";
		}
		else if (ch == 5)
		{
			return 1;
		}
		else
		{
			cout << "Wrong input\n";
			goto label;
		}
		return 1;
	}
};

class Course
{
	string courseid;
	// string coursename;
	// int listofstudents;
	// Quiz quiz;
};

class Result
{
	int quizid;
	string studentid;
	int marks;
	// displayresult();
};
class Analytics
{ public:
   
   void analytics()
{
   


string topics[11] = {"Programming Fundamentals", "Object Oriented Programming", "Introduction To Computing", "Data Structures", "Analysis of Algorithms", "Software Requirements Engineering", "Research Methodology", "Big Data Analytics", "Artificial Intelligence", "Deep Learning", "Digital Image Processing"};
    int data[11] = {8, 9, 7, 6, 8, 5, 4, 7, 9, 9, 6};

    cout << "Topic                      | Data" << endl;
    cout << "----------------------------|--------" << endl;

    for (int i = 0; i < 11; i++) {
        cout << left << setw(28) << setfill(' ') << topics[i] << "| ";
        for (int k = 0; k < data[i]; k++) {
            cout << "*";
        }
        cout << endl;
    }
}
};
struct generalMenu
{
	void start()

	{
	meu:
		int n;
		cout << "\t!!!Welcome!!!" << endl;
		cout << "Type 1 to login for Teacher \n";
		cout << "Type 2 to login for Student \n";
		cout << "Type 0 to Exit\n";
		cin >> n;
		if (n == 0)
		{
			
			cout << "Thank You!\n";
		}
		else if (n != 1 && n != 2)
		{
			cout << "Invalid input\n";
			goto meu;
		}

		else if (n == 1)
			while (1)
			{
				cout << "Type TeacherID: ";
				string id;
				cin >> id;
				string pass;
				cout << "Type Password: ";
				cin >> pass;
				for (int i = 0; i < pass.length(); i++)
					cout << "*";
				cout << endl;
				ifstream file("teacher.csv");
				string name, password, cours, line;

				while (getline(file, line))
				{
					stringstream ss(line);
					getline(ss, name, ',');
					getline(ss, password, ',');
					getline(ss, cours, ',');
					if (name == id)
						break;
				}
				if (name != id || password != pass)
				{
					cout << "wrong password\n";
				}
				else
				{
					Teacher t1(name, cours);
					if (t1.teacherMenu())
						goto meu;
					break;
				}
			}
		else if (n == 2)
		{
			bool found = false;
			string id;

			while (1)
			{
				cout << "Student ID: ";

				cin >> id;
				string pass;
				cout << "Type Password: ";
				cin >> pass;
				for (int i = 0; i < pass.length(); i++)
					cout << "*";
				cout << endl;

				ifstream file("Crd.csv");
				string line;
				while (getline(file, line))
				{
					stringstream ss(line);
					string s;
					getline(ss, s, ','); // skip the first column (Roll No.)
					while (getline(ss, s, ','))
					{ // loop over the remaining columns
						if (s == id)
						{
							found = true;
							break;
						}
					}
					if (found)
					{
						break;
					}
				}
				if (found)
				{
					break;
				}
				else
				{
					cout << "Incorrect ID /Password\n";
				}

				file.close();
			}
			if (found)
			{ // cout<<"id "<<id<<endl;
				string rollno, name;
				int courses[11];
				Student s1;
				ifstream file("Crd.csv");
				string line;
				getline(file, line); // skip first line
				getline(file, line); // skip second line

				while (getline(file, line))
				{
					// getline(file,line, ',');
					char *token = strtok(const_cast<char *>(line.c_str()), ",");
					if (token != nullptr)
					{
						// Skip the first column
						token = strtok(NULL, ",");
						if (token != nullptr)
						{
							rollno = string(token);
						}
						// cout<<rollno;
						if (id == rollno)
						{
							s1.setid(rollno);
							token = strtok(NULL, ",");
							name = string(token);
							s1.setname(name);
							// cout<<name;
							for (int i = 0; i < 11; i++)
							{
								token = strtok(NULL, ",");
								courses[i] = stoi(token);
							}
							s1.setcourses(courses);
						}
					}
				}

				if (s1.studentMenu())
					goto meu;
				file.close();
			}
		}
	}

	void main()
	{
		while (2)
		{
			cout << "╔════════════════════════════════════════════════════╗" << endl;
			cout << "║             Welcome to the Quiz system             ║" << endl;
			cout << "║                by Aitazaz Kamran                   ║" << endl;
			cout << "║                                                    ║" << endl;
			cout << "║      1.View Courses Available                      ║" << endl;
			cout << "║      2.Login                                       ║" << endl;
			cout << "║      3.Exit                                        ║" << endl;
			cout << "║      4.View analytics                              ║" << endl;
			cout << "╚════════════════════════════════════════════════════╝" << endl;
			int m;
			cin >> m;
			string array[11] = {{"Programming Fundamentals"}, {"Object Oriented Programming"}, {"Introduction To Computing"}, {"Data Structures"}, {"Analysis of Algorithms"}, {"Software Requirements Engineering"}, {"Research Methodology"}, {"Big Data Analytics"}, {"Artificial Intelligence"}, {"Deep Learning"}, {"Digital Image Processing"}};

			switch (m)
			{
			case 1:
				for (int i = 0; i < 11; i++)
				{
					cout << array[i] << endl;
				}
				break;
			case 2:
				start();
				break;
			case 3:
				break;
			}
			
			if (m==4)
			{
				Analytics a;
			a.analytics();
			}
		}
	}
};
int main()
{
	generalMenu s1;
	s1.main();

	return 0;
}
