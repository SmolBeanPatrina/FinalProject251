#include "student.hpp"
#include "list.hpp"
#include <iostream>
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi

int main()
{
    DSLinkedList domestic_students;
    ISLinkedList intern_students;
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if (!domesticFile.is_open())
    {
        std::cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);

    int stu_count = 1;
    while (getline(domesticFile, line))
    {
        istringstream ss(line);

        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        int temp_id = 20210000 + stu_count;

        DomesticStudent temp_student(firstName, lastName, cgpa, researchScore, temp_id, province);

        domestic_students.AddNode(temp_student);

        // domestic_students.Sort();

        stu_count++;
    }

    domesticFile.close();
    // domestic_students.print();

    string line2;
    ifstream InternationalFile("international-stu.txt");
    if (!InternationalFile.is_open())
    {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    //Read the first line of international-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(InternationalFile, line2);

    while (getline(InternationalFile, line2))
    {

        istringstream ss(line2);

        string firstName, lastName, country, s_cgpa, s_researchScore, s_r, s_l, s_s, s_w;
        float cgpa;
        int researchScore;
        int r, l, s, w;

        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, country, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        getline(ss, s_r, ',');
        r = atoi(s_r.c_str());

        getline(ss, s_l, ',');
        l = atoi(s_l.c_str());

        getline(ss, s_s, ',');
        s = atoi(s_s.c_str());

        getline(ss, s_w, ',');
        w = atoi(s_w.c_str());

        int temp_id = 20210000 + stu_count; //creates unique student # for each student

        InternationalStudent temp_student(firstName, lastName, cgpa, researchScore, temp_id, country, r, l, s, w); //creates new student

        intern_students.AddNode(temp_student); //put new students into a vector

        stu_count++;
    }

    domestic_students.Sort();

    domestic_students.print();

    InternationalFile.close();

    intern_students.Sort();

    intern_students.print();

    SLinkedList students(domestic_students, intern_students);
    
    students.print();


    int x;

    std::cin >> x;

    return 0;
}