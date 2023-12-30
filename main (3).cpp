#include <iostream>
#include <string>
using namespace std;

//struct part for the linked List DS 
struct Part {
	string name ;
	string memory;
	string code;
	float price;
	string ManufacturerName;
	Part *next_part;
	
} *part_temp=NULL, *part_cur=NULL, *part_head=NULL, *part_tail=NULL;

//struct Manufacturer for the linked List DS 
struct Manufacturer {
	string name;
	string phone;
	string address;
	string Email;
	Part *p ;
	Manufacturer *next_manufactrer;
} *manufacturer_temp=NULL, *manufacturer_cur=NULL, *manufacturer_head=NULL, *manufacturer_tail=NULL;

//function to add Part
void addPart()
   {
    part_temp=new Part;
    
    cout<<"Enter The Part Name:\n";
    cin>>part_temp->name;  
    
    cout<<"Enter The Part Memory:\n";
    cin>>part_temp->memory;  
    
    cout<<"Enter The Part Code:\n";
    cin>>part_temp->code;
    
    cout<<"Enter The Part Price:\n"; 
    cin>>part_temp->price;  
    
     cout<<"Enter The Part Manufacturer:\n"; 
    cin>>part_temp->ManufacturerName;  
    
    part_temp->next_part=NULL;        
    if (part_head==NULL)   
    {
        part_head=part_temp;        
        part_tail=part_temp;
    } else
    {   
        part_tail->next_part=part_temp;
        part_tail=part_temp;  
        }
}

//function to add Manufacturer
void addManufacturer()
{ 
    manufacturer_temp=new Manufacturer;
    
    
  cout<<"Enter The Manufacturer Name:\n";
    cin>>manufacturer_temp->name; 
    
    cout<<"Enter The Manufacturer Phone:\n";
    cin>>manufacturer_temp->phone;  
    
    cout<<"Enter The Manufacturer Address:\n";
    cin>>manufacturer_temp->address; 
    
    cout<<"Enter The Manufacturer Email:\n";  
    cin>>manufacturer_temp->Email;   
    
    
    
    
    
    manufacturer_temp->next_manufactrer=NULL;        
    if (manufacturer_head==NULL)   
    {
        manufacturer_head=manufacturer_temp;       
        manufacturer_tail=manufacturer_temp;
    }else
    {
        manufacturer_tail->next_manufactrer=manufacturer_temp;
        manufacturer_tail=manufacturer_temp;   
        }
}

//function to display Parts list 
void displayParts(){
     Part *part_temp = part_head;
    
     if (part_head==NULL){
         cout<<"List is Empty! \n";
     }
     else {
         cout<<"Parts List display: \n";
         while(part_temp != NULL){
             cout<<"Part's Name: "<<part_temp->name<<endl;
             cout<<"Part's Memory: "<<part_temp->memory<<endl;
             cout<<"Part's Code: "<<part_temp->code<<endl;
             cout<<"Part's Price: "<<part_temp->price<<endl;
             cout<<"Part's Manufacturer: "<<part_temp->ManufacturerName<<endl;
             cout<<"------------------------------------\n";
             part_temp = part_temp->next_part;
         }
     }
}

//function to display Manufacturer Parts list 
void displayManufacturers()
{
    Manufacturer* manufacturer_temp = manufacturer_head;

    if(manufacturer_head == NULL)
    {
        cout<<"There is no Manufacturers to show!!\n";
    }
    else
    {
        cout<<"Manufacturers List Display: \n";
        while(manufacturer_temp != NULL)
        {
            cout<< "Manufacturer Name: " << manufacturer_temp->name <<endl;
            cout<< "Manufacturer Phone:" << manufacturer_temp->phone <<endl;
            cout<< "Manufacturer Address:" << manufacturer_temp->address <<endl;
            cout<< "Manufacturer Email:" << manufacturer_temp->Email <<endl;
            cout<<"---------------------------------------------------------------\n";
            
		    manufacturer_temp = manufacturer_temp->next_manufactrer;
        }
        cout<<endl;
    }
}

// Function to assign a part to a manufacturer
void assignPartToManufacturer() {
    string partCode, manufacturerName;

    cout << "Enter the Part Code to assign: ";
    cin >> partCode;

    Part *partCur = part_head;
    bool partFound = false;

    while (partCur != NULL) {
        if (partCur->code == partCode) {
            partFound = true;
            break;
        }
        partCur = partCur->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " not found." << endl;
        return;
    }

    cout << "Enter the Manufacturer Name to assign the part: ";
    cin >> manufacturerName;

    Manufacturer *manufacturerCur = manufacturer_head;
    bool manufacturerFound = false;

    while (manufacturerCur != NULL) {
        if (manufacturerCur->name == manufacturerName) {
            manufacturerFound = true;
            break;
        }
        manufacturerCur = manufacturerCur->next_manufactrer;
    }

    if (!manufacturerFound) {
        cout << "Manufacturer with name " << manufacturerName << " not found." << endl;
        return;
    }

    // Assign the part to the manufacturer
    partCur->next_part = manufacturerCur->p;
    manufacturerCur->p = partCur;

    cout << "Part with code \"" << partCode << "\" assigned to Manufacturer \"" << manufacturerName << "\" successfully." << endl;
}

// Function to remove a part from a manufacturer
void removePartFromManufacturer() {
    string partCode, manufacturerName;

    cout << "Enter the Part Code to remove from Manufacturer: ";
    cin >> partCode;

    Part *partCur = part_head;
    bool partFound = false;

    while (partCur != NULL) {
        if (partCur->code == partCode) {
            partFound = true;
            break;
        }
        partCur = partCur->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " not found." << endl;
        return;
    }

    cout << "Enter the Manufacturer Name to remove the part from: ";
    cin >> manufacturerName;

    Manufacturer *manufacturerCur = manufacturer_head;
    bool manufacturerFound = false;

    while (manufacturerCur != NULL) {
        if (manufacturerCur->name == manufacturerName) {
            manufacturerFound = true;
            break;
        }
        manufacturerCur = manufacturerCur->next_manufactrer;
    }

    if (!manufacturerFound) {
        cout << "Manufacturer with name " << manufacturerName << " not found." << endl;
        return;
    }

    Part *partPrev = NULL;
    Part *partTemp = manufacturerCur->p;

    while (partTemp != NULL) {
        if (partTemp->code == partCode) {
            partFound = true;
            if (partPrev == NULL) {
                // If the part to be removed is the first part in the manufacturer's list
                manufacturerCur->p = partTemp->next_part;
            } else {
                partPrev->next_part = partTemp->next_part;
            }
            delete partTemp;
            break;
        }
        partPrev = partTemp;
        partTemp = partTemp->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " is not associated with Manufacturer " << manufacturerName << "." << endl;
    } else {
        cout << "Part with code \"" << partCode << "\" removed from Manufacturer \"" << manufacturerName << "\" successfully." << endl;
    }
}
// update part
void updatePart() {
    string partCode;

    cout << "Enter the Part Code to update: ";
    cin >> partCode;

    Part *partCur = part_head;
    bool partFound = false;

    while (partCur != NULL) {
        if (partCur->code == partCode) {
            partFound = true;
            break;
        }
        partCur = partCur->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " not found." << endl;
        return;
    }

    cout << "Enter the updated Part Name: ";
    cin >> partCur->name;

    cout << "Enter the updated Part Memory: ";
    cin >> partCur->memory;

    cout << "Enter the updated Part Price: ";
    cin >> partCur->price;

    cout << "Part with code \"" << partCode << "\" updated successfully." << endl;
}

//update manufacturere
void updateManufacturer() {
    string manufacturerName;

    cout << "Enter the Manufacturer Name to update: ";
    cin >> manufacturerName;

    Manufacturer *manufacturerCur = manufacturer_head;
    bool manufacturerFound = false;

    while (manufacturerCur != NULL) {
        if (manufacturerCur->name == manufacturerName) {
            manufacturerFound = true;
            break;
        }
        manufacturerCur = manufacturerCur->next_manufactrer;
    }

    if (!manufacturerFound) {
        cout << "Manufacturer with name " << manufacturerName << " not found." << endl;
        return;
    }

    cout << "Enter the updated Manufacturer Phone: ";
    cin >> manufacturerCur->phone;

    cout << "Enter the updated Manufacturer Address: ";
    cin >> manufacturerCur->address;

    cout << "Enter the updated Manufacturer Email: ";
    cin >> manufacturerCur->Email;

    cout << "Manufacturer \"" << manufacturerName << "\" updated successfully." << endl;
}

//delete part
void deletePart() {
    string partCode;

    cout << "Enter the Part Code to delete: ";
    cin >> partCode;

    Part *partPrev = NULL;
    Part *partCur = part_head;
    bool partFound = false;

    while (partCur != NULL) {
        if (partCur->code == partCode) {
            partFound = true;
            break;
        }
        partPrev = partCur;
        partCur = partCur->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " not found." << endl;
        return;
    }

    if (partPrev == NULL) {
        // If the part to be deleted is the first part in the list
        part_head = partCur->next_part;
    } else {
        partPrev->next_part = partCur->next_part;
    }

    delete partCur;
    cout << "Part with code \"" << partCode << "\" deleted successfully." << endl;
}

//delete manufacturer
void deleteManufacturer() {
    string manufacturerName;

    cout << "Enter the Manufacturer Name to delete: ";
    cin >> manufacturerName;

    Manufacturer *manufacturerPrev = NULL;
    Manufacturer *manufacturerCur = manufacturer_head;
    bool manufacturerFound = false;

    while (manufacturerCur != NULL) {
        if (manufacturerCur->name == manufacturerName) {
            manufacturerFound = true;
            break;
        }
        manufacturerPrev = manufacturerCur;
        manufacturerCur = manufacturerCur->next_manufactrer;
    }

    if (!manufacturerFound) {
        cout << "Manufacturer with name " << manufacturerName << " not found." << endl;
        return;
    }

    if (manufacturerPrev == NULL) {
        // If the manufacturer to be deleted is the first manufacturer in the list
        manufacturer_head = manufacturerCur->next_manufactrer;
    } else {
        manufacturerPrev->next_manufactrer = manufacturerCur->next_manufactrer;
    }

    delete manufacturerCur;
    cout << "Manufacturer \"" << manufacturerName << "\" deleted successfully." << endl;
}


// Function to search for part details by part code
void searchPartDetails() {
    string partCode;
    cout << "Enter the Part Code to search: ";
    cin >> partCode;

    Part *partCur = part_head;
    bool partFound = false;

    while (partCur != NULL) {
        if (partCur->code == partCode) {
            partFound = true;
            cout << "Part Details for Code \"" << partCode << "\":" << endl;
            cout << "Part Name: " << partCur->name << endl;
            cout << "Part Memory: " << partCur->memory << endl;
            cout << "Part Price: " << partCur->price << endl;
            cout << "Part Manufacturer: " << partCur->ManufacturerName << endl;
            break;
        }
        partCur = partCur->next_part;
    }

    if (!partFound) {
        cout << "Part with code " << partCode << " not found." << endl;
    }
}
// Function to search for manufacturer details by manufacturer name
void searchManufacturerDetails() {
    string manufacturerName;
    cout << "Enter the Manufacturer Name to search: ";
    cin >> manufacturerName;

    Manufacturer *manufacturerCur = manufacturer_head;
    bool manufacturerFound = false;

    while (manufacturerCur != NULL) {
        if (manufacturerCur->name == manufacturerName) {
            manufacturerFound = true;
            cout << "Manufacturer Details for Name \"" << manufacturerName << "\":" << endl;
            cout << "Manufacturer Name: " << manufacturerCur->name << endl;
            cout << "Manufacturer Phone: " << manufacturerCur->phone << endl;
            cout << "Manufacturer Address: " << manufacturerCur->address << endl;
            cout << "Manufacturer Email: " << manufacturerCur->Email << endl;
            break;
        }
        manufacturerCur = manufacturerCur->next_manufactrer;
    }

    if (!manufacturerFound) {
        cout << "Manufacturer with name " << manufacturerName << " not found." << endl;
    }
}


//Main Function
int main (){
    
    int chioce;
    string code;
    string  manufacturer_name; 
     
    do{
        cout<<"\n\nComputer Parts Management Services:\n ";
        cout<<"------------------------------------";
        cout << "\n1) Add new Part ";
        cout << "\n2) Add new manufacturer ";
        cout << "\n3) Display part's List ";
        cout << "\n4) Display Manufacturer's List ";
        cout << "\n5) Assign Part To Manufacturer ";
        cout << "\n6) Remove Part From Manufacturer ";
        cout << "\n7) Update part ";
        cout << "\n8) Update manufacturer ";
        cout << "\n9) Delete part ";
        cout << "\n10) Delete manufacturer ";
        cout << "\n11) Search Part Details by Code ";
        cout << "\n12) Search Manufacturer Details by Name ";
        cout << "\n13) Exit... \n";
        cout<<"------------------------------------";
        cout<<"\nEnter your Choice: ";
        cin>>chioce;
        
        switch(chioce){
            case 1 : 
               addPart();
               break;
            case 2: 
               addManufacturer();
               break;
            case 3: 
                displayParts();
                break;
            case 4: 
                displayManufacturers();
                break;
            case 5:
                assignPartToManufacturer();
                break;
            case 6:
                removePartFromManufacturer();
                break;
            case 7:
                updatePart();
                break;
            case 8:
                updateManufacturer();
                break;
            case 9:
                deletePart();
                break;
            case 10:
                deleteManufacturer();
                break;
            case 11:
                searchPartDetails();
                break;
            case 12:
                searchManufacturerDetails();
                break;
            case 13:
               cout<<"Exiting.....";
               break;
            default:
               cout<<"Your Choice is wrong, try again ";
               
        }
        
    } while (chioce !=13);
    
}
