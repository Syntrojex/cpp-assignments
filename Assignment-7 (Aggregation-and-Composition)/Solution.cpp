//25l-3107


#include <iostream>
#include <cstring>  
using namespace std;

int strlength(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

//-------------- Address Class-------------------

class Address
{
private:
    char* street;
    char* city;
    char* country;

public:
    Address(const char* street, const char* city, const char* country);
    Address(const Address& other);
    Address& operator=(const Address& other);
    ~Address();
    void display() const;

};


Address::Address(const char* street, const char* city, const char* country)
{
    int len1 = strlength(street);
    int len2 = strlength(city);
    int len3 = strlength(country);

    this->street = new char[len1 + 1];
    this->city = new char[len2 + 1];
    this->country = new char[len3 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(this->street + i) = *(street + i);
    }
    this->street[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(this->city + i) = *(city + i);
    }
    this->city[len2] = '\0';

    for (int i = 0; i < len3; i++)
    {
        *(this->country + i) = *(country + i);
    }
    this->country[len3] = '\0';
}

Address::Address(const Address& other)
{
    int len1 = strlength(other.street);
    int len2 = strlength(other.city);
    int len3 = strlength(other.country);

    street = new char[len1 + 1];
    city = new char[len2 + 1];
    country = new char[len3 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(street + i) = *(other.street + i);
    }
    street[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(city + i) = *(other.city + i);
    }
    city[len2] = '\0';

    for (int i = 0; i < len3; i++)
    {
        *(country + i) = *(other.country + i);
    }
    country[len3] = '\0';
}

Address& Address::operator=(const Address& other)
{
    if (this != &other)
    {
        delete[] street;
        delete[] city;
        delete[] country;

        int len1 = strlength(other.street);
        int len2 = strlength(other.city);
        int len3 = strlength(other.country);

        street = new char[len1 + 1];
        city = new char[len2 + 1];
        country = new char[len3 + 1];

        for (int i = 0; i < len1; i++)
        {
            *(street + i) = *(other.street + i);
        }
        street[len1] = '\0';

        for (int i = 0; i < len2; i++)
        {
            *(city + i) = *(other.city + i);
        }
        city[len2] = '\0';

        for (int i = 0; i < len3; i++)
        {
            *(country + i) = *(other.country + i);
        }
        country[len3] = '\0';
    }
    return *this;
}

Address::~Address()
{
    delete[] street;
    delete[] city;
    delete[] country;
}

void Address::display() const
{
    cout << "\nAddress : " << street << ", " << city << ", " << country;
}



//-------------- Course Class-------------------

class Course
{
private:
    char* courseCode;
    char* courseName;
    int creditHours;
public:
    Course();
    Course(const char* code, const char* name, int credits);
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();
    const char* getCode() const;
    void display() const;
};

Course::Course()
{
    courseCode = nullptr;
    courseName = nullptr;
    creditHours = 0;
}

Course::Course(const char* code, const char* name, int credits) : creditHours(credits)
{
    int len1 = strlength(code);
    int len2 = strlength(name);

    courseCode = new char[len1 + 1];
    courseName = new char[len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(courseCode + i) = *(code + i);
    }
    courseCode[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(courseName + i) = *(name + i);
    }
    courseName[len2] = '\0';
}

Course::Course(const Course& other) : creditHours(other.creditHours)
{
    int len1 = strlength(other.courseCode);
    int len2 = strlength(other.courseName);

    courseCode = new char[len1 + 1];
    courseName = new char[len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(courseCode + i) = *(other.courseCode + i);
    }
    courseCode[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(courseName + i) = *(other.courseName + i);
    }
    courseName[len2] = '\0';
}

Course& Course::operator=(const Course& other)
{
    if (this != &other)
    {
        delete[] courseCode;
        delete[] courseName;

        int len1 = strlength(other.courseCode);
        int len2 = strlength(other.courseName);

        courseCode = new char[len1 + 1];
        courseName = new char[len2 + 1];

        for (int i = 0; i < len1; i++)
        {
            *(courseCode + i) = *(other.courseCode + i);
        }
        courseCode[len1] = '\0';

        for (int i = 0; i < len2; i++)
        {
            *(courseName + i) = *(other.courseName + i);
        }
        courseName[len2] = '\0';

        creditHours = other.creditHours;
    }
    return *this;
}

Course::~Course()
{
    delete[] courseCode;
    delete[] courseName;
}

const char* Course::getCode() const
{
    return courseCode;
}


void Course::display() const
{
    cout << "[Course] " << courseCode << " - " << courseName << " (" << creditHours << " Credit Hours)";
}






//-------------- Professor Class-------------------

class Professor
{
private:
    char* name;
    char* employeeId;
    char* specialization;
    Address address;

public:
    Professor(const char* name, const char* id, const char* specialization, const Address& addr);
    Professor(const Professor& other);
    Professor& operator=(const Professor& other);
    ~Professor();
    const char* getId() const;
    void display() const;
};

Professor::Professor(const char* name, const char* id, const char* specialization, const Address& addr) : address(addr)
{
    int len1 = strlength(name);
    int len2 = strlength(id);
    int len3 = strlength(specialization);

    this->name = new char[len1 + 1];
    employeeId = new char[len2 + 1];
    this->specialization = new char[len3 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(this->name + i) = *(name + i);
    }
    this->name[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(employeeId + i) = *(id + i);
    }
    employeeId[len2] = '\0';

    for (int i = 0; i < len3; i++)
    {
        *(this->specialization + i) = *(specialization + i);
    }
    this->specialization[len3] = '\0';
}

Professor::Professor(const Professor& other) : address(other.address)
{
    int len1 = strlength(other.name);
    int len2 = strlength(other.employeeId);
    int len3 = strlength(other.specialization);

    name = new char[len1 + 1];
    employeeId = new char[len2 + 1];
    specialization = new char[len3 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(name + i) = *(other.name + i);
    }
    name[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(employeeId + i) = *(other.employeeId + i);
    }
    employeeId[len2] = '\0';

    for (int i = 0; i < len3; i++)
    {
        *(specialization + i) = *(other.specialization + i);
    }
    specialization[len3] = '\0';
}

Professor& Professor::operator=(const Professor& other)
{
    if (this != &other)
    {
        delete[] name;
        delete[] employeeId;
        delete[] specialization;

        int len1 = strlength(other.name);
        int len2 = strlength(other.employeeId);
        int len3 = strlength(other.specialization);

        name = new char[len1 + 1];
        employeeId = new char[len2 + 1];
        specialization = new char[len3 + 1];

        for (int i = 0; i < len1; i++)
        {
            *(name + i) = *(other.name + i);
        }
        name[len1] = '\0';

        for (int i = 0; i < len2; i++)
        {
            *(employeeId + i) = *(other.employeeId + i);
        }
        employeeId[len2] = '\0';

        for (int i = 0; i < len3; i++)
        {
            *(specialization + i) = *(other.specialization + i);
        }
        specialization[len3] = '\0';

        address = other.address;
    }
    return *this;
}

Professor::~Professor()
{
    delete[] name;
    delete[] employeeId;
    delete[] specialization;
}

const char* Professor::getId() const
{
    return employeeId;
}

void Professor::display() const
{
    cout << "Professor : " << name << " [ID: " << employeeId << "]\n";
    cout << "Specialization : " << specialization << endl;
    address.display();
    cout << endl;
}

//-------------- Student Class-------------------

class Student
{
private:
    char* name;
    char* rollNumber;
    int semester;
    Address address;
    Course** enrolledCourses;
    int courseCount;

public:

    Student(const char* name, const char* roll, int semester, const Address& addr);
    ~Student();
    void enrollCourse(Course* course);
    void dropCourse(const char* courseCode);
    const char* getRoll() const;
    void display() const;
};

Student::Student(const char* name, const char* roll, int semester, const Address& addr) : address(addr)
{
    courseCount = 0;
    enrolledCourses = nullptr;

    int len1 = strlength(name);
    int len2 = strlength(roll);

    this->name = new char[len1 + 1];
    rollNumber = new char[len2 + 1];

    for (int i = 0; i < len1; i++)
    {
        *(this->name + i) = *(name + i);
    }
    this->name[len1] = '\0';

    for (int i = 0; i < len2; i++)
    {
        *(rollNumber + i) = *(roll + i);
    }
    rollNumber[len2] = '\0';

    this->semester = semester;
}

Student::~Student()
{
    delete[] name;
    delete[] rollNumber;
    delete[] enrolledCourses;
}

void Student::enrollCourse(Course* course)
{
    for (int i = 0; i < courseCount; ++i)
    {
        if (strcmp(enrolledCourses[i]->getCode(), course->getCode()) == 0)
        {
            cout << "Error: " << name << " is already enrolled in " << course->getCode() << "\n";
            return;
        }
    }

    Course** temp = new Course * [courseCount + 1];

    for (int i = 0; i < courseCount; ++i)
    {
        temp[i] = enrolledCourses[i];
    }

    temp[courseCount] = course;

    delete[] enrolledCourses;

    enrolledCourses = temp;
    courseCount++;

    cout << name << " enrolled in " << course->getCode() << "\n";
}

void Student::dropCourse(const char* courseCode)
{
    int index = -1;

    for (int i = 0; i < courseCount; ++i)
    {
        if (strcmp(enrolledCourses[i]->getCode(), courseCode) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Error: " << name << " is not enrolled in " << courseCode << "\n";
        return;
    }

    for (int i = index; i < courseCount - 1; ++i)
    {
        enrolledCourses[i] = enrolledCourses[i + 1];
    }

    courseCount--;

    cout << name << " dropped " << courseCode << "\n";
}

const char* Student::getRoll() const
{
    return rollNumber;
}

void Student::display() const
{
    cout << "\nStudent: " << name << " [Roll: " << rollNumber << " ]";
    cout << "\nSemester: " << semester;
    address.display();
    cout << "\nEnrolled Courses:\n";

    if (courseCount == 0)
    {
        cout << "No courses enrolled\n";
    }
    else
    {
        for (int i = 0; i < courseCount; ++i)
        {
            cout << "[" << i + 1 << "] ";
            enrolledCourses[i]->display();
            cout << endl;
        }
    }
    cout << "------------------------------------\n\n";
}



//-------------- Department Class-------------------

class Department
{
private:
    char* departmentName;
    char* departmentCode;
    Course* courses;
    int courseCount;
    Professor** professors;
    int professorCount;

public:

    Department(const char* name, const char* code);
    ~Department();
    void addCourse(const char* code, const char* name, int credits);
    void assignProfessor(Professor* prof);
    void removeProfessor(const char* employeeId);
    Course* getCourse(const char* courseCode);
    const char* getCode() const;
    void display() const;
};


Department::Department(const char* name, const char* code)
{
    int len1 = strlength(name);
    int len2 = strlength(code);

    departmentName = new char[len1 + 1];
    departmentCode = new char[len2 + 1];


    for (int i = 0; i < len1; i++)
    {
        *(departmentName + i) = *(name + i);
    }
    departmentName[len1] = '\0';


    for (int i = 0; i < len2; i++)
    {
        *(departmentCode + i) = *(code + i);
    }
    departmentCode[len2] = '\0';


    courses = nullptr;
    courseCount = 0;
    professors = nullptr;
    professorCount = 0;
}

Department::~Department()
{
    delete[] departmentName;
    delete[] departmentCode;
    delete[] courses;
    delete[] professors;
}


void Department::addCourse(const char* code, const char* name, int credits)
{
    Course* temp = new Course[courseCount + 1];

    for (int i = 0; i < courseCount; i++)
        temp[i] = courses[i];

    temp[courseCount] = Course(code, name, credits);

    delete[] courses;
    courses = temp;
    courseCount++;

    cout << "> " << code << " - " << name << " (" << credits << " Cr)" << endl;
}


void Department::assignProfessor(Professor* prof)
{
    for (int i = 0; i < professorCount; i++)
    {
        if (strcmp(professors[i]->getId(), prof->getId()) == 0)
        {
            cout << "Error: Professor already assigned to Department " << departmentCode << endl;
            return;
        }
    }

    Professor** temp = new Professor * [professorCount + 1];

    for (int i = 0; i < professorCount; i++)
    {
        temp[i] = professors[i];
    }

    temp[professorCount] = prof;

    delete[] professors;
    professors = temp;
    professorCount++;

    cout << "> Professor " << prof->getId() << " assigned to " << departmentCode << endl;
}



void Department::removeProfessor(const char* employeeId)
{
    int index = -1;

    for (int i = 0; i < professorCount; i++)
    {
        if (strcmp(professors[i]->getId(), employeeId) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Error: Professor " << employeeId << " not found in department " << departmentCode << endl;
        return;
    }


    for (int i = index; i < professorCount - 1; i++)
    {
        professors[i] = professors[i + 1];
    }

    professorCount--;
    cout << "> Professor " << employeeId << " removed from " << departmentCode << endl;
}


Course* Department::getCourse(const char* courseCode)
{
    for (int i = 0; i < courseCount; i++)
    {
        if (strcmp(courses[i].getCode(), courseCode) == 0)
            return &courses[i];
    }
    return nullptr;
}


const char* Department::getCode() const
{
    return departmentCode;
}


void Department::display() const
{
    cout << "Department: " << departmentName << " [" << departmentCode << "]\n";
    cout << "Courses Offered:\n";

    if (courseCount == 0)
        cout << "No courses\n";
    else
        for (int i = 0; i < courseCount; i++)
        {
            cout << "  ";
            courses[i].display();
            cout << endl;
        }

    cout << "Assigned Professors:\n";

    if (professorCount == 0)
        cout << "No professors\n";
    else
        for (int i = 0; i < professorCount; i++)
        {
            professors[i]->display();
        }
    cout << "========================================\n\n";
}




//-------------- University Class-------------------

class University
{
private:
    char* universityName;
    char* location;
    Department** departments;
    int deptCount;
    Student** students;
    int studentCount;

public:

    University(const char* name, const char* location);
    ~University();
    void addDepartment(const char* name, const char* code);
    Department* getDepartment(const char* code);
    void registerStudent(Student* student);
    void removeStudent(const char* rollNumber);
    void display() const;
};


University::University(const char* name, const char* loc)
{
    int len1 = strlength(name);
    int len2 = strlength(loc);

    universityName = new char[len1 + 1];
    location = new char[len2 + 1];


    for (int i = 0; i < len1; i++)
    {
        *(universityName + i) = *(name + i);
    }
    universityName[len1] = '\0';


    for (int i = 0; i < len2; i++)
    {
        *(location + i) = *(loc + i);
    }
    location[len2] = '\0';


    departments = nullptr;
    deptCount = 0;
    students = nullptr;
    studentCount = 0;
}



University::~University()
{
    delete[] universityName;
    delete[] location;

    for (int i = 0; i < deptCount; i++)
        delete departments[i];

    delete[] departments;
    delete[] students;
}


void University::addDepartment(const char* name, const char* code)
{
    Department** temp = new Department * [deptCount + 1];

    for (int i = 0; i < deptCount; i++)
    {
        temp[i] = departments[i];
    }

    temp[deptCount] = new Department(name, code);

    delete[] departments;
    departments = temp;
    deptCount++;

    cout << "> Department " << code << " added: " << name << "\n";
}

Department* University::getDepartment(const char* code)
{
    for (int i = 0; i < deptCount; i++)
    {
        if (strcmp(departments[i]->getCode(), code) == 0)
            return departments[i];

    }
    return nullptr;
}

void University::registerStudent(Student* stu)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i]->getRoll(), stu->getRoll()) == 0)
        {
            cout << "Error: Student " << stu->getRoll() << " already registered.\n";
            return;
        }
    }

    Student** temp = new Student * [studentCount + 1];

    for (int i = 0; i < studentCount; i++)
    {
        temp[i] = students[i];
    }

    temp[studentCount] = stu;
    delete[] students;

    students = temp;
    studentCount++;

    cout << "> Student " << stu->getRoll() << " registered.\n";
}



void University::removeStudent(const char* roll)
{
    int idx = -1;

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i]->getRoll(), roll) == 0)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "Error: Student " << roll << " not found.\n";
        return;
    }

    for (int i = idx; i < studentCount - 1; i++)
    {
        students[i] = students[i + 1];
    }

    studentCount--;
    cout << "> Student " << roll << " removed.\n";
}

void University::display() const
{
    cout << "\n\n========================================\n";
    cout << "UNIVERSITY: " << universityName << " | " << location << "\n";
    cout << "========================================\n";

    if (deptCount == 0)
        cout << "No departments available\n";
    else
        for (int i = 0; i < deptCount; i++)
        {
            departments[i]->display();
        }

    cout << "Registered Students: " << studentCount << "\n";

    if (studentCount == 0)
    {
        cout << "No students registered\n";
    }
    else
    {
        for (int i = 0; i < studentCount; i++)
            students[i]->display();
    }

    cout << "========================================\n";
}










//-------------- MAIN FUNCTION ------------------

int main()
{
    cout << "\n\n===== Step 1: Create Professors Independently =====\n";

    Address addr1("47-B Sunset Boulevard", "Karachi", "Pakistan");
    Address addr2("9-C Moonlight Avenue", "Peshawar", "Pakistan");
    Address addr3("12-A Garden Street", "Lahore", "Pakistan");
    Address addr4("33-D Hill Road", "Islamabad", "Pakistan");


    Professor p1("Ma'am Anoosha Khan", "P-1001", "OOP", addr1);
    Professor p2("Sir Razi Uddin", "P-1002", "DSA", addr2);
    Professor p3("Ma'am Arooj Khalil", "P-1003", "Networks", addr3);
    Professor p4("Sir Zeeshan Ali Rana", "P-1004", "Databases", addr4);

    cout << "Professors created independently:\n";
    p1.display(); p2.display(); p3.display(); p4.display();
    cout << endl;




    cout << "\n\n===== Step 2: Build University and Add Departments =====\n";

    University uni("FAST-NUCES", "Lahore, Pakistan");

    uni.addDepartment("Computer Science", "CS");
    uni.addDepartment("Electrical Engineering", "EE");

    uni.display();





    cout << "\n\n===== Step 3: Add Courses to Departments =====\n";

    Department* cs = uni.getDepartment("CS");

    cs->addCourse("CS301", "Object Oriented Programming", 3);
    cs->addCourse("CS302", "Data Structures", 3);
    cs->addCourse("CS401", "Computer Networks", 3);

    Department* ee = uni.getDepartment("EE");

    ee->addCourse("EE201", "Circuit Analysis", 3);
    ee->addCourse("EE305", "Signals & Systems", 3);

    uni.display();




    cout << "\n\n===== Step 4: Assign Professors to Departments =====\n";

    cs->assignProfessor(&p1);
    cs->assignProfessor(&p2);
    ee->assignProfessor(&p3);
    ee->assignProfessor(&p4);
    cs->assignProfessor(&p3);

    uni.display();



    cout << "\n\n===== Step 5: Duplicate Assignment Edge Case =====\n";

    cs->assignProfessor(&p1);
    cout << endl;



    cout << "\n\n===== Step 6: Create Students and Enroll in Courses =====\n";

    Address sAddr1("7-D Johar Town", "Lahore", "Pakistan");
    Address sAddr2("9-C Model Town", "Lahore", "Pakistan");
    Address sAddr3("15-B Gulberg", "Lahore", "Pakistan");

    Student s1("Ali Hassan", "22I-1045", 5, sAddr1);
    Student s2("Sara Ahmed", "22I-1062", 5, sAddr2);
    Student s3("Hamza Malik", "22I-1078", 3, sAddr3);

    s1.enrollCourse(cs->getCourse("CS301"));
    s1.enrollCourse(cs->getCourse("CS302"));
    s1.enrollCourse(cs->getCourse("CS401"));

    s1.display();




    cout << "\n\n===== Step 7: Duplicate Enrollment Edge Case =====\n";

    s1.enrollCourse(cs->getCourse("CS301"));
    cout << endl;



    cout << "\n\n===== Step 8: Drop a Course (Aggregation Proof) =====\n";

    s1.dropCourse("CS401");
    Course* check = cs->getCourse("CS401");

    if (check)
    {
        check->display();
    }
    cout << endl;





    cout << "\n\n===== Step 9: Remove a Professor from Department (Aggregation Proof) =====\n";

    cs->removeProfessor("P-1002");
    p2.display();
    cout << endl;



    cout << "\n\n===== Step 10: Register Students with University (Aggregation) =====\n";

    uni.registerStudent(&s1);
    uni.registerStudent(&s2);
    uni.registerStudent(&s3);
    uni.registerStudent(&s1);
    uni.display();



    cout << "\n\n===== Step 11: Destroy University (Composition + Aggregation Proof) =====\n";
    {
        University tempUni("COMSATS", "Islamabad");

        tempUni.addDepartment("CS", "CS");

        Department* d = tempUni.getDepartment("CS");

        d->addCourse("CS101", "Intro to CS", 3);
        d->assignProfessor(&p4);
        tempUni.registerStudent(&s1);

    }

    cout << "> p4 still exists: "; p4.display();
    cout << "> s1 still exists: "; s1.display();
    cout << endl;



    cout << "===== Step 12: Destroy Professor (Composition Proof: Address gone with them) =====\n";
    {
        Address tmpAddr("99-Z Test Street", "Multan", "Pakistan");
        Professor tmpProf("Dr. Test", "P-9999", "Testing", tmpAddr);

        tmpProf.display();
    }


    cout << "Professor destroyed, address gone with them.\n";

    return 0;
}