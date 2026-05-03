#include <iostream>
#include <conio.h>
using namespace std;

const int total_employee = 550;
int current_employee = 10;
int employees_leave=15;

// Data Structure
string employee_name[total_employee] = {"ali", "zara", "faiza", "nisa", "shayaan", "ayaan", "abdullah", "manal", "faria", "gul"};
int employee_ID[total_employee] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
float employee_salary[total_employee] = {60000, 50000, 70000, 56000, 90000, 45000, 78000, 65000, 55000, 78000};
int employee_age[total_employee] = {25, 56, 45, 32, 23, 34, 35, 33, 22, 40};
string employee_address[total_employee] = {"lahore", "Munro", "Islamabad", "Karachi", "Multan", "Mianwali", "Gojra", "Dgkhan", "peshawar", "basti"};
float employee_meeting[total_employee] = {2.00, 4.00, 6.00, 8.00, 9.00, 3.00, 5.00, 6.00, 5.00, 2.00};
int employee_leave[total_employee] = {15,8,9,5,3,0,2,3,4,5};

// Function declarations 
void showMainMenu();
void adminLoginPage();
void showAdminPanel();
void showAllEmployees();
void addNewEmployeeRecord();
void deleteEmployeeRecord();
void updateEmployeeRecord();
void searchEmployee();
void giveIncrement();
void showApplicants();
void hirePeople();
void showEmployeePanel();
void showMyInfo();
void updateMyInfo();
void checkMySalary();
void myIncrement();
void myMeetingSchedule();
int findEmployeeByName(string name);
int findEmployeeByID(int id);
void applyingforleave();
bool checkAdminCredentials();

// main function 
int main()
{
    while (true)
    {
        showMainMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        cout << "Your choice is: " << choice << endl;
        
        if (choice == 1)
        {
            adminLoginPage();
        }
        else if (choice == 2)
        {
            showEmployeePanel();
        }
        else if (choice == 3)
        {
            cout << "Thanks for using our system! Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Wrong option! Press any key...";
            getch();
        }
    }
    return 0;
}

//  Main Menu Header
void showMainMenu()
{
    system("cls");
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << "-----------------    --------SOFTWARE HOUSE MANAGEMENT SYSTEM--------      ---------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Admin" << endl;
    cout << "2. Employee" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
}

// Admin Login attempt
bool checkAdminCredentials()
{
    int attempts = 0;
    for (int i = 1; i <= 3; i++)
    {
        string username;
        int pass;
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter the password: ";
        cin >> pass;
        
        if (username == "Admin" && pass == 1234)
        {
            cout << "Welcome Admin! Login successful!" << endl;
            return true;
        }
        else
        {
            cout << "Wrong username or password! ";
        }
    }
    return false;
}

// Admin login page
void adminLoginPage()
{
    system("cls");
    if (checkAdminCredentials())
    {
        cout << endl;
        showAdminPanel();
    }
    else
    {
        cout << "Too many wrong attempts! Press any key...";
        getch();
    }
}

//  find employee by name
int findEmployeeByName(string name)
{
    for (int i = 0; i < current_employee; i++)
    {
        if (employee_name[i] == name)
        {
            return i;
        }
    }
    return -1;
}

//  find employee by ID
int findEmployeeByID(int Id)
{
    for (int i = 0; i < current_employee; i++)
    {
        if (employee_ID[i] == Id)
        {
            return i;
        }
    }
    return -1;
}

// Display all employees Recoed
void showAllEmployees()
{
    system("cls");
    
    cout << "Name \t Age \t Salary \t ID \t Address" << endl;

    for (int i = 0; i < current_employee; i++)
    {
        if (employee_name[i] != "")
        {
            cout << employee_name[i] << "\t " 
                 << employee_age[i] << "\t " 
                 << employee_salary[i] << "\t " 
                 << employee_ID[i] << "\t " 
                 << employee_address[i] << endl;
        }
    }
    cout<<endl;
    cout << "Press any key to go back...";
    getch();
}

// Adding new employees 
void addNewEmployeeRecord()
{
    system("cls");
    int n;
    cout << "Enter the number of employees you want to add: ";
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        if (current_employee < total_employee)
        {
            string name, address;
            int age, Id;
            float salary;
            float meetingTime;
            
           
            cout << "Name: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Address: ";
            cin >> address;
            cout << "ID: ";
            cin >> Id;
            cout << "Salary: ";
            cin >> salary;
            cout << "Meeting time (hours): ";
            cin >> meetingTime;
            
            employee_name[current_employee] = name;
            employee_age[current_employee] = age;
            employee_address[current_employee] = address;
            employee_ID[current_employee] = Id;
            employee_salary[current_employee] = salary;
            employee_meeting[current_employee] = meetingTime;
            
            current_employee++;
            cout << "Employee added successfully!" << endl;
        }
        else
        {
            cout << "Employee cannot be added!" << endl;
            break;
        }
    }
    cout<<endl;
    cout << "Press any key to continue...";
    getch();
}

// Deleting  employee record
void deleteEmployeeRecord()
{
    system("cls");
    string name;
    cout << "Enter employee name to delete: ";
    cin >> name;
    
    int index = findEmployeeByName(name);
    
    if (index != -1)
    {
        // clearing all data
        employee_name[index] = "";
        employee_age[index] = 0;
        employee_address[index] = "";
        employee_ID[index] = 0;
        employee_salary[index] = 0;
        employee_meeting[index] = 0;
        
        cout << "Record of " << name << " has been deleted!" << endl;
    }
    else
    {
        cout << "No record found with name: " << name << endl;
    }
    cout<<endl;
    cout << "Press any key to continue...";
    getch();
}

// Updating existing employee Record
void updateEmployeeRecord()
{
    system("cls");
    string name;
    cout << "Enter employee name to update: ";
    cin >> name;
    
    int index = findEmployeeByName(name);
    
    if (index != -1)
    {
        int age, ID;
        float salary;
        string new_name, address;
        
        cout << "========== OLD RECORD ==========" << endl;
        cout << "Name: " << employee_name[index] << endl;
        cout << "Age: " << employee_age[index] << endl;
        cout << "Salary: " << employee_salary[index] << endl;
        cout << "Address: " << employee_address[index] << endl;
        cout << "ID: " << employee_ID[index] << endl;
        
        cout << "\n========== ENTER NEW DATA ==========" << endl;
        cout << "New name: ";
        cin >> new_name;
        cout << "New address: ";
        cin >> address;
        cout << "New ID: ";
        cin >> ID;
        cout << "New age: ";
        cin >> age;
        cout << "New salary: ";
        cin >> salary;
        
        employee_name[index] = new_name;
        employee_address[index] = address;
        employee_ID[index] = ID;
        employee_age[index] = age;
        employee_salary[index] = salary;
        
        cout << "Record updated successfully!" << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

// Search employee by name
void searchEmployee()
{
    system("cls");
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    
    int index = findEmployeeByName(name);
    
    if (index != -1)
    {
       
        cout << "Name: " << employee_name[index] << endl;
        cout << "Age: " << employee_age[index] << endl;
        cout << "Salary: " << employee_salary[index] << endl;
        cout << "ID: " << employee_ID[index] << endl;
        cout << "Address: " << employee_address[index] << endl;
        cout << "Meeting hours: " << employee_meeting[index] << endl;
    }
    else
    {
        cout << "No employee found with name: " << name << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

//  10% annual increment to employee salary
void giveIncrement()
{
    system("cls");
    string name;
    cout << "Enter employee name for increment: ";
    cin >> name;
    
    int index = findEmployeeByName(name);
    
    if (index != -1)
    {
        float percent = 10;
        float incrementAmount = employee_salary[index] * (percent / 100);
        
        cout << "Old Salary: " << employee_salary[index] << endl;
        employee_salary[index] = employee_salary[index] + incrementAmount;
        cout << "New Salary after " << percent << "% increment: " << employee_salary[index] << endl;
        cout << "Increment applied successfully!" << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

//  viewing list of applicants 
void showApplicants()
{
    system("cls");
    int count;
    cout << "Enter number of applicants you want to add:";
    cin >> count;
    
    string names[100];
    int ages[100], experiences[100];
    float desiredSalaries[100];
    
    for (int i = 0; i < count; i++)
    {
        cout << "\n--- Applicant " << (i + 1) << " ---" << endl;
        cout << "Name: ";
        cin >> names[i];
        cout << "Age: ";
        cin >> ages[i];
        cout << "Expected salary: ";
        cin >> desiredSalaries[i];
        cout << "Experience (years): ";
        cin >> experiences[i];
    }
    
    cout << "--- Applicants List ---" << endl;
    for (int i = 0; i < count; i++)
    {
            cout <<"Name:"  << names[i] <<endl;
            cout <<" Age: " << ages[i] <<endl;
            cout <<"Expected Salary: " << desiredSalaries[i] <<endl;
            cout <<"Experience: " << experiences[i] << " years" << endl;
    }
    
    cout << "Press any key to continue...";
    getch();
}

// Hiring applicants based on THeir  experience
void hirePeople()
{
    system("cls");
    int count;
    cout << "Enter number of applicants you want to review: ";
    cin >> count;
    
    for (int i = 0; i < count; i++)
    {
        string name;
        int experience;
        
        cout<<"------Reviewing Applicants--------";
        cout << "Name: ";
        cin >> name;
        cout << "Enter your Experience : ";
        cin >> experience;
        
        if (experience > 5)
        {
            cout << "Congratulations " << name << " You're hired!";
            cout << endl;
        }
        else
        {
            cout  << name << " you need more experience!";
            cout << endl;
        }
    }
    
    cout << "Press any key to continue...";
    getch();
}

// Admin main panel
void showAdminPanel()
{
    while (true)
    {
        system("cls");
        cout << "==================== ADMIN PANEL ====================" << endl;
        cout << "1. View all employees" << endl;
        cout << "2. Add new employee" << endl;
        cout << "3. Delete employee" << endl;
        cout << "4. Update employee" << endl;
        cout << "5. Search employee" << endl;
        cout << "6. Give annual increment" << endl;
        cout << "7. View job applicants" << endl;
        cout << "8. Hire job applicants" << endl;
        cout << "9. Exit admin panel" << endl;
        cout << "=====================================================" << endl;
        
        int option;
        cout << "Enter your choice: ";
        cin >> option;
        
        if (option == 1)
        {
            showAllEmployees();
        }
        else if (option == 2)
        {
            addNewEmployeeRecord();
        }
        else if (option == 3)
        {
            deleteEmployeeRecord();
        }
        else if (option == 4)
        {
            updateEmployeeRecord();
        }
        else if (option == 5)
        {
            searchEmployee();
        }
        else if (option == 6)
        {
            giveIncrement();
        }
        else if (option == 7)
        {
            showApplicants();
        }
        else if (option == 8)
        {
            hirePeople();
        }
        else if (option == 9)
        {
            cout << "Exit the admin panel..." << endl;
            break;
        }
        else
        {
            cout << "Invalid option! Press any key...";
            getch();
        }
    }
}

//  view my information
void showMyInfo()
{
    system("cls");
    cout << "========== MY PROFILE ==========" << endl;
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id);
    
    if (index != -1)
    {
        cout << "\n--- Your Details ---" << endl;
        cout << "Name: " << employee_name[index] << endl;
        cout << "Age: " << employee_age[index] << endl;
        cout << "Salary: " << employee_salary[index] << endl;
        cout << "ID: " << employee_ID[index] << endl;
        cout << "Address: " << employee_address[index] << endl;
        cout << "Meeting hours: " << employee_meeting[index] << endl;
    }
    else
    {
        cout << "Employee ID not found!" << endl;
    }
    cout<<endl;
    cout << "Press any key to continue...";
    getch();
}

//  update my Profile 
void updateMyInfo()
{
    system("cls");
    cout << "========== UPDATE MY PROFILE ==========" << endl;
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id);
    
    if (index != -1)
    {
        cout << "Name: " << employee_name[index] << endl;
        cout << "Age: " << employee_age[index] << endl;
        cout << "Address: " << employee_address[index] << endl;


        string address;
        int age;
        
        cout << "New address: ";
        cin >> address;
        cout << "New age: ";
        cin >> age;
        
        employee_age[index] = age;
        employee_address[index] = address;
        
        cout<<endl;
        cout << "Your profile updated!" << endl;
    }
    else
    {
        cout << "Employee ID not found!" << endl;
    }
    cout << endl;
    cout << "Press any key to continue...";
    getch();
}

//  check my salary
void checkMySalary()
{
    system("cls");
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id);
    
    if (index != -1)
    {
        cout << "\nHello " << employee_name[index] << "!" << endl;
        cout << "Your current salary is: " << employee_salary[index] << endl;
    }
    else
    {
        cout << "Wrong ID! No record found!" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

//  My increment 
void myIncrement()
{
    system("cls");
    cout << "========== MY INCREMENT ==========" << endl;
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id);
    
    if (index != -1)
    {
        float percent = 10;
        float incrementAmount = employee_salary[index] * (percent / 100);
        
        cout << "Employee: " << employee_name[index] << endl;
        cout << "Old Salary: Rs. " << employee_salary[index] << endl;
        employee_salary[index] = employee_salary[index] + incrementAmount;
        cout << "New Salary after " << percent << "% increment: Rs. " << employee_salary[index] << endl;
        cout << "Annual increment applied!" << endl;
    }
    else
    {
        cout << "Employee not found!" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}

// checking meeting schedule
void myMeetingSchedule()
{
    system("cls");
    cout << "========== MEETING SCHEDULE ==========" << endl;
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id);
    
    if (index != -1)
    {
        cout << "\nEmployee: " << employee_name[index] << endl;
        cout << "Your meeting time: " << employee_meeting[index] << " hours per week" << endl;
    }
    else
    {
        cout << "Invalid ID! No record found!" << endl;
    }
    cout << "Press any key to continue...";
    getch();
}
// Applying for leave
 void applyingforleave(){
    
    int id;
    cout << "Enter your Employee ID: ";
    cin >> id;
    
    int index = findEmployeeByID(id); 
    
    if (index != -1) 
    {
        cout << "Employee Name: " << employee_name[index] ;
        cout << endl;
        cout << "Remaining Leaves: " << employee_leave[index] ;
        cout << " days" << endl;
        
        int leave;
        cout << "Enter the number of days for leave: ";
        cin >> leave;
        
        if(leave<=0)
        {
            cout << "Invalid number of days!" << endl;
        }
        else if(leave<=employee_leave[index]) 
        {   
            // Deduction of leave
            employee_leave[index] = employee_leave[index] - leave;
            cout << " Your leave has been approved!" << endl;
            cout << "Leave days: " << leave ;
            cout << endl;
            cout << "Remaining leaves: " << employee_leave[index];
            cout << endl;
        }
        else
        {
            cout << " Leave balance not available!" << endl;
            cout << "You only have days left" << employee_leave[index] ;
            cout << endl;
        }
    }
    else
    {
        cout << "Employee ID not found!" << endl;
    }
    
    cout << "Press any key to continue...";
    getch();
}
// Employee panel
void showEmployeePanel()
{
    while (true)
    {
        system("cls");
        cout << "==================== EMPLOYEE PANEL ====================" << endl;
        cout << "1. View my profile" << endl;
        cout << "2. Update my profile" << endl;
        cout << "3. View my salary" << endl;
        cout << "4. Check my increment" << endl;
        cout << "5. View meeting schedule" << endl;
        cout << "6. Apply for leave" << endl;
        cout << "7. Exit" << endl;
        cout << "========================================================" << endl;
        
        int option;
        cout << "Enter your choice: ";
        cin >> option;
        
        if (option == 1)
        {
            showMyInfo();
        }
        else if (option == 2)
        {
            updateMyInfo();
        }
        else if (option == 3)
        {
            checkMySalary();
        }
        else if (option == 4)
        {
            myIncrement();
        }
        else if (option == 5)
        {
            myMeetingSchedule();
        }
        else if(option==6)
        {
            applyingforleave();
        }
        else if (option == 7)
        {
            cout << "Leaving employee panel..." << endl;
            break;
        }
        else
        {
            cout << "Invalid option! Press any key...";
            getch();
        }
    }
}