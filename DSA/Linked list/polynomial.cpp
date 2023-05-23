#include <bits/stdc++.h>
using namespace std;
class Poly{
    public:
    float coeff;
    int exp;
    Poly* next;

    Poly(float x, int y)
    {
        coeff = x;
        exp = y;
        next = NULL;
    }
    Poly()
    {
        coeff = 0;
        exp = 0;
        next = NULL;
    }
};

void removeDuplicates(Poly* head)
{
    Poly *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {
 
            if (ptr1->exp == ptr2->next->exp) {
 
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

Poly* Attach(float x, int y, Poly* head)
{
    Poly *temp = head;
    Poly* new_Poly = new Poly(x,y);
    if(temp == NULL)
    {
        return new_Poly;
    }
    
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_Poly;
    removeDuplicates(head);
    return head;
}

Poly* Zero()
{
    return new Poly(0.0,0);
}

int IsZero(Poly* head)
{
    Poly* temp = head;
    while(temp->next != NULL)
    {
        if(temp->coeff != 0.0 && temp->exp != 0)
            return 1;
    }
    return 0;
}

float Coef(Poly* head, int exp)
{
    Poly* temp = head;
    while(temp->next != NULL)
    {
        if(temp->exp == exp)
            return temp->coeff;
    }
    return 0.00;
}

int LeadExp(Poly* head)
{
    Poly* temp = head;
    int max_power = INT_MIN;
    while (temp->next != NULL)
    {
        max_power = max(max_power,temp->exp);
    }
    return max_power;
    
}

void Remove(Poly** head,int exp)
{
    Poly* new_head = *head, *prev = NULL;
    if(exp == new_head->exp)
    {
        *head = new_head->next;
        delete new_head;
        return;
    }
    else{

        while (new_head != NULL && new_head->exp != exp)
        {
            prev = new_head;
            new_head = new_head->next;
        }

        if(new_head == NULL)
        {
            cout << "Exponent not found" << endl;
            return;
        }

        prev->next = new_head->next;
        delete new_head;
    }

}

void Print(Poly *head)
{
    Poly* temp = head;
    while(temp->exp != 0)
    {
        cout << temp->coeff << "x^" << temp->exp;
        cout << "+";
        temp = temp->next;
    }
    cout << temp->coeff << endl;
}

Poly* Add(Poly* head1, Poly* head2,Poly* result)
{
    Poly* p1 = head1, *p2 = head2;
    while(p1->next != NULL && p2->next != NULL)
    {
        (p1->exp > p2->exp) ? result->exp = p1->exp : result->exp = p2->exp;
        (p1->exp > p2->exp) ? result->coeff = p1->coeff : result->coeff = p2->coeff;
        (p1->exp > p2->exp) ? p1 = p1->next : p2 = p2->next;

        if(p1->exp == p2->exp)
        {
            result->exp = p1->exp;
            result->coeff = p1->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        result = result->next;
        result->next = NULL;
    }
    while(p1->next)
    {
        result->exp = p1->exp;
        result->coeff = p1->coeff;
        p1 = p1->next;
        result = result->next;
        result->next = NULL;
    }
    while(p2->next)
    {
        result->exp = p2->exp;
        result->coeff = p2->coeff;
        p2 = p2->next;
        result = result->next;
        result->next = NULL;
    }
    removeDuplicates(result);
    return result;
}


 
Poly* multiply(Poly* poly1, Poly* poly2, Poly* poly3)
{
    Poly *ptr1, *ptr2;
    ptr1 = poly1;
    ptr2 = poly2;
    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            int coeff, power;
 
            coeff = ptr1->coeff * ptr2->coeff;

            power = ptr1->exp + ptr2->exp;
 
            poly3 = Attach(coeff,power,poly3);

            ptr2 = ptr2->next;
        }
 
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
 
    removeDuplicates(poly3);
    return poly3;
}

int main()
{
    int cnt = 1;
    vector<Poly*> poly(10,NULL); 
    cout << "Welcome to my programme !!" << endl;
    while (1)
    {
        int m;
        cout << "Instructions!!" << endl;
        cout << "Press 0 to exit" << endl;
        cout << "Press 1 to create a Polynomial" << endl;
        cout << "Press 2 to create zero Polynomial" << endl;
        cout << "Press 3 to check Polynomial is Zero Polynomial or not" << endl;
        cout << "Press 4 to find coefficient of specific exponent of x" << endl;
        cout << "Press 5 to get the highest power of polynomial" << endl;
        cout << "Press 6 to remove exponent power term from specific polynomial" << endl;
        cout << "Press 7 to add two polynomial" << endl;
        cout << "Press 8 to Multiply two Polynomial" << endl;
        cout << "Press 9 to Print Polynomial" << endl;
        cin >> m;

        if(m == 0)
            exit(0);
        else if( m == 1)
        {
            cout << "Enter " << cnt << " Polynomial:-" << endl;
            while(1)
            {
                float x;
                int y,z;
                cout << "Enter coefficient and power of polynomial by giving space between them : ";
                cin >> x >> y;
                poly[cnt] = Attach(x,y,poly[cnt]);
                cout << "Enter 0 to exit or 1 to continue" << endl;
                cin >> z;
                if(z == 0)
                    break;
            }
            cnt++;
        }
        else if(m == 2)
        {
            cout << "Polynomial " << cnt << "is zero Polynomial" << endl;
            poly[cnt] = Zero();
            cnt++;
        }
        else if(m == 3)
        {
            int a;
            cout << "Enter polynomial number which you want to check : ";
            cin >> a;
            if(IsZero(poly[a]))
                cout << "Given polynomial is not Zero Polynomial" << endl;
            else
                cout << "Given polynomial is Zero Polynomial" << endl;
        }
        else if(m == 4)
        {
            int exp,b;
            cout << "Enter polynomial number : ";
            cin >> b;
            cout << "Enter exponent of x whose coefficient you want to know: ";
            cin >> exp;
            cout << "Required Coefficient is " << Coef(poly[b],exp) << endl;
        }
        else if(m == 5)
        {
            int c;
            cout << "Enter Polynomial number : ";
            cin >> c;
            cout << "Maximum degree of x in given polynomial is " << LeadExp(poly[c]) << endl;
        }
        else if(m == 6)
        {
            int d,exp;
            cout << "Enter Polynomial number: ";
            cin >> d;
            cout << "Enter exponent you want to delete : ";
            cin >> exp;
            Remove(&poly[d],exp);
            cout << "Removed Successfully" << endl;
        }
        else if(m == 7)
        {
            Poly* result = new Poly();
            int p1,p2;
            cout << "Enter first Polynomial number: ";
            cin >> p1;
            cout << "Enter second Polynomial number :";
            cin >> p2;
            result = Add(poly[p1],poly[p2],result);
            Print(result);
        }
        else if(m == 8)
        {
            Poly* result = NULL;
            int p1,p2;
            cout << "Enter first Polynomial number: ";
            cin >> p1;
            cout << "Enter second Polynomial number :";
            cin >> p2;
            result = multiply(poly[p1],poly[p2],result);
            Print(result);
        }
        else if(m == 9)
        {
            int g;
            cout << "Enter polynomial number : ";
            cin >> g;
            Print(poly[g]);
        }
    }
    
    return 0;
}