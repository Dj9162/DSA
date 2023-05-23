#include <iostream>
using namespace std;
#define MAX 100

class scholar_number{
    private:
        int *num;
        int i;
    public:
        scholar_number()
        {
            num = new int[MAX];
            i = 0;
        }
        void setnum(int n)
        {
            i++;
            num[i] = n;
        }
        int getnum()
        {
            return num[i];
        }

};

class studentName{
    private:
    string first_name, middle_name, last_name;
    public:
        void setname(string first, string middle, string last)
        {
            first_name = first;
            middle_name = middle;
            last_name = last;
        }

        string get_first()
        {
            return first_name;
        }
        string getname()
        {
            return (first_name+" "+middle_name+" "+last_name);
        }

};

class studentList{
    public:
    int age;
    studentName name;
    scholar_number marks;
    studentList* next;
};

void insert(studentList **head)
{
    studentList* new_node = new studentList();
    string f,m,l;
    int number,n;
    cout << "Enter first name of student: ";
    cin >> f;
    cout << "Enter middle name of student: ";
    cin >> m;
    cin.ignore();
    cout << "Enter last name of student: ";
    cin >> l;

    cout << "Enter Marks of student: ";
    cin >> number;
    cout << "Enter age of student: ";
    cin >> n;
    new_node->name.setname(f,m,l);
    new_node->marks.setnum(number);
    new_node->age = n;
    
    studentList* last = *head;
    new_node->next = NULL;
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next !=NULL)
        last = last->next;

    last->next = new_node;
    cout << "Data inserted Succesfully" << endl;
    return;
    
}

void delete_element( studentList** head, int snum)
{
    studentList* temp = *head;                               
    studentList* prev = NULL;                   

    if ( temp !=NULL && temp->marks.getnum() == snum)           
    {
        *head = temp->next;            
        delete temp;               
        return;
    }
    else        
    {
        while ( temp !=NULL && temp->marks.getnum() != snum)     
        {
            prev = temp;
            temp = temp->next;
        }

        if( temp == NULL)           
            cout << "Did not Found!" << endl;
        
        prev->next = temp->next;

        delete temp;
        
    }
    cout << "Data deleted Successfully" << endl;
  
}

void searchByScholar(studentList* head, int n)
{
    if(head == NULL)
    {
        cout << "NOT FOUND !!" << endl;
        return;
    }
    if(head->marks.getnum() == n)
    {
        cout << "Informations of Student: " << endl;
        cout << "Name of Student: " << head->name.getname() << endl;
        cout << "Marks of Student: " << head->marks.getnum() << endl;
        cout << "Age of Student: " << head->age << endl;
        return;
    }
    searchByScholar( head->next,n);
}

void searchByFirstName(studentList* head, string n)
{
    if(head == NULL)
    {
        cout << "NOT FOUND !!" << endl;
        return;
    }

    if(head->name.get_first() == n)
    {
        cout << "Informations of Student: " << endl;
        cout << "Name of Student: " << head->name.getname() << endl;
        cout << "Marks of Student: " << head->marks.getnum() << endl;
        cout << "Age of Student: " << head->age << endl;
        return;
    }
    searchByFirstName(head->next,n);
}

void printList(studentList* head)
{
    studentList* temp = head;
    cout << "Student List:-" << endl;
    while(temp != NULL)
    {
        cout << temp->name.getname() << endl;
        temp = temp->next;
    }
    return;
}

void countStudents(studentList* head)
{
    int n = 1;
    studentList* temp = head;
    while(temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }
    cout << "Total number of students is " << n << endl;
    return;
}

int main()
{
    studentList* head = new studentList();
    head = NULL;
    string Name;
    int number,n;

    while(1)
    {
        cout << "\n\tWELCOCME" << endl;
        cout << "Press 1 to insert student data" << endl;
        cout << "Press 2 to Delete student data" << endl;
        cout << "Press 3 to Search student data" << endl;
        cout << "Press 4 to Print the complete stored list of students" << endl;
        cout << "Press 5 to count total number of students" << endl;
        cout << "Press 0 to Exit" << endl;
        cout << endl;
        int choice;
        cout << "Enter your Choice: ";
        cin >> choice;
        if(choice == 1)
        {
            insert(&head);
        }
        else if(choice == 2)
        {
            cout << "Enter scholar Number you want to delete: ";
            cin >> number;
            delete_element(&head,number);
        }
        else if(choice == 3)
        {
            cout << "Now Press 1 to search student by scholar number: " << endl;
            cout << "Or Press 2 to search student by his first name: "<< endl;
            int temp;
            cin >> temp;
            if(temp == 1)
            {
                int r;
                cout << "Enter Scholar number: ";
                cin >> r;
                searchByScholar(head,r);
            }
            else if(temp == 2)
            {
                cout << "Enter first name of student: ";
                cin >> Name;
                searchByFirstName(head,Name);
            }
            else
                cout << "Invalid Input" << endl;
        }
        else if(choice == 4)
        {
            printList(head);
        }
        else if(choice == 5)
        {
            countStudents(head);
        }
        else if(choice == 0)
            exit(0);
        else
            cout << "Invalid Choice " << "\n" << "Try Again\n" << endl;

    }
    
    return 0;
}