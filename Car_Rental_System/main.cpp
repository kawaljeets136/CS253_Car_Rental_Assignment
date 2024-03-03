#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class User
{
protected:
    string Name;
    string ID;
    string Password;
};

class Customer : private User
{
public:
    friend int return_request(string ID, string file_name, float x);
    friend int browse_cars(float x, string ID);
    friend void rent_request(string file_name, string id, float x);
    friend void fine(string file_name, string id);
    friend int search_car(string model_no);
    friend int search_member(string file_name, string member_id);
    friend vector<string> search_id(string id_no, string file_name);
    friend vector<string> search_model(string model);
    friend vector<string> search_pass(string password, string file_name);
};

class Employee : private User
{
public:
    friend int return_request(string ID, string file_name, float x);
    friend int browse_cars(float x, string ID);
    friend void rent_request(string file_name, string id, float x);
    friend void fine(string file_name, string id);
    friend int search_car(string model_no);
    friend int search_member(string file_name, string member_id);
    friend vector<string> search_id(string id_no, string file_name);
    friend vector<string> search_model(string model);
    friend vector<string> search_pass(string password, string file_name);
};

int search_car(string model_no)
{
    ifstream inputFile;
    inputFile.open("Car.csv");
    string line = "";
    int flag = 0;
    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string Model;
        string Condition;
        int Is_rented;
        string renter_ID;
        float rent_price;
        string due_date;
        string temp = "";

        getline(inputString, Model, ',');
        getline(inputString, Condition, ',');
        getline(inputString, temp, ',');
        Is_rented = stoi(temp);
        temp = "";
        getline(inputString, renter_ID, ',');
        getline(inputString, temp, ',');
        rent_price = stof(temp);
        temp = "";
        getline(inputString, due_date, '\n');

        if (model_no == Model)
        {
            flag = 1;
            break;
        }
        line = "";
    }
    if (flag == 0)
    {
        return 0;
    }
    else
        return 1;
}

int search_member(string file_name, string member_id)
{
    ifstream inputFile;
    inputFile.open(file_name);
    string line = "";
    int flag = 0;
    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string ID;
        string Name;
        string Password;
        int rented_cars;
        float fine;
        string record;
        int car_limit;
        string temp = "";

        getline(inputString, ID, ',');
        getline(inputString, Name, ',');
        getline(inputString, Password, ',');
        getline(inputString, temp, ',');
        rented_cars = stoi(temp);
        temp = "";
        getline(inputString, temp, ',');
        fine = stof(temp);
        temp = "";
        getline(inputString, record, ',');
        getline(inputString, temp, '\n');
        car_limit = stoi(temp);
        temp = "";

        if (ID == member_id)
        {
            flag = 1;
            break;
        }
        line = "";
    }
    if (flag == 0)
    {
        return 0;
    }
    else
        return 1;
}

vector<string> search_id(string id_no, string file_name)
{
    vector<string> StoreData;
    ifstream inputFile;
    inputFile.open(file_name);
    string line = "";

    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string Customer_id;
        string Customer_name;
        string Password;
        string Rented_cars_str;
        string Fine_due_str;
        string Customer_record;
        string Car_limit_str;

        getline(inputString, Customer_id, ',');
        getline(inputString, Customer_name, ',');
        getline(inputString, Password, ',');
        getline(inputString, Rented_cars_str, ',');
        getline(inputString, Fine_due_str, ',');
        getline(inputString, Customer_record, ',');

        getline(inputString, Car_limit_str, '\n');

        if (id_no == Customer_id)
        {
            StoreData.push_back(Customer_id);
            StoreData.push_back(Customer_name);
            StoreData.push_back(Password);
            StoreData.push_back(Rented_cars_str);
            StoreData.push_back(Fine_due_str);
            StoreData.push_back(Customer_record);
            StoreData.push_back(Car_limit_str);
            break;
        }
        line = "";
    }
    return StoreData;
}

vector<string> search_model(string model)
{
    vector<string> StoreData;
    ifstream inputFile;
    inputFile.open("Car.csv");
    string line = "";

    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string Model;
        string condition;
        string is_rented;
        string renter_id;
        string price;
        string due_date;

        getline(inputString, Model, ',');
        getline(inputString, condition, ',');
        getline(inputString, is_rented, ',');
        getline(inputString, renter_id, ',');
        getline(inputString, price, ',');
        getline(inputString, due_date, '\n');

        if (Model == model)
        {
            StoreData.push_back(Model);
            StoreData.push_back(condition);
            StoreData.push_back(is_rented);
            StoreData.push_back(renter_id);
            StoreData.push_back(price);
            StoreData.push_back(due_date);
            break;
        }
        line = "";
    }
    return StoreData;
}

vector<string> search_pass(string password, string file_name)
{
    vector<string> StoreData;
    ifstream inputFile;
    inputFile.open(file_name);
    string line = "";

    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string Customer_id;
        string Customer_name;
        string Password;
        string Rented_cars_str;
        string Fine_due_str;
        string Customer_record;
        string Car_limit_str;

        getline(inputString, Customer_id, ',');
        getline(inputString, Customer_name, ',');
        getline(inputString, Password, ',');
        getline(inputString, Rented_cars_str, ',');
        getline(inputString, Fine_due_str, ',');
        getline(inputString, Customer_record, ',');

        getline(inputString, Car_limit_str, '\n');

        if (password == Password)
        {
            StoreData.push_back(Customer_id);
            StoreData.push_back(Customer_name);
            StoreData.push_back(Password);
            StoreData.push_back(Rented_cars_str);
            StoreData.push_back(Fine_due_str);
            StoreData.push_back(Customer_record);
            StoreData.push_back(Car_limit_str);
            break;
        }
        line = "";
    }
    return StoreData;
}

void rent_request(string file_name, string id, float x)
{
    string car_model;
    std::cout << "Enter the Model of the car that you want to rent: ";
    std::cin >> car_model;
    vector<string> car_rec = search_model(car_model);
    if (car_rec.size() == 0)
    {
        std::cout << "Car with model " << car_model << " doesn't exist in database. Enter valid car id\n\n";
        system("pause");
        std::cout << endl;
        return;
    }
    if (car_rec[2] != "0")
    {
        std::cout << "Currently car is not available for rent\n\n";
        system("pause");
        std::cout << endl;
        return;
    }
    fstream read_file;
    read_file.open(file_name);
    if (read_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return;
    }
    vector<string> lines;
    string line;
    while (getline(read_file, line))
    {
        lines.push_back(line);
        stringstream inputString(line);
        string curr_ID;
        getline(inputString, curr_ID, ',');
        if (curr_ID == id)
        {
            string name;
            string password;
            int rented_cars;
            string fine;
            string record;
            int car_limit;
            float price;
            string temp = "";
            getline(inputString, name, ',');
            getline(inputString, password, ',');
            getline(inputString, temp, ',');
            rented_cars = stoi(temp);
            temp = "";
            getline(inputString, fine, ',');
            getline(inputString, record, ',');
            getline(inputString, temp, '\n');
            car_limit = stoi(temp);
            temp = "";
            if (car_limit == rented_cars)
            {
                std::cout << "Car rent limit reached.\n\n";
                system("pause");
                std::cout << endl;
                return;
            }
            int days;
            std::cout << "Enter the number of days you want to rent the car: ";
            std::cin >> days;
            price = stof(car_rec[4]);
            std::cout << "Rent price for " << days << " days will be : " << price * x * days << endl;
            char choice;
            std::cout << "Do you want to rent " << car_rec[0] << " for rent price " << days * price * x << " (y/n)? ";
            std::cin >> choice;
            if (choice == 'n')
            {
                std::cout << "\n\n";
                return;
            }
            rented_cars++;
            line = curr_ID + "," + name + "," + password + "," + to_string(rented_cars) + "," + fine + "," + record + "," + to_string(car_limit);
            lines.pop_back();
            lines.push_back(line);
            line = "";
        }
    }
    read_file.close();

    ofstream write_file;
    write_file.open(file_name);
    if (write_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return;
    }
    for (int i = 0; i < lines.size(); i++)
    {
        write_file << lines[i] << endl;
    }
    write_file.close();

    // update car
    read_file.open("Car.csv");
    if (read_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return;
    }
    vector<string> lines1;
    string line2 = "";
    while (getline(read_file, line2))
    {
        lines1.push_back(line2);
        stringstream inputString(line2);
        string curr_ID;
        getline(inputString, curr_ID, ',');
        if (curr_ID == car_rec[0])
        {
            string cond;
            string is_rented;
            string renter_id;
            string price;
            string due_date;
            getline(inputString, cond, ',');
            getline(inputString, is_rented, ',');
            getline(inputString, renter_id, ',');
            getline(inputString, price, ',');
            getline(inputString, due_date, '\n');
            is_rented = "1";
            renter_id = id;
            std::cout << "Enter return date of car(DD-MM-YYYY): ";
            std::cin >> due_date;
            line2 = curr_ID + "," + cond + "," + is_rented + "," + renter_id + "," + price + "," + due_date;
            lines1.pop_back();
            lines1.push_back(line2);
            line2 = "";
        }
    }
    read_file.close();

    write_file.open("Car.csv");
    if (write_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return;
    }
    for (int i = 0; i < lines1.size(); i++)
    {
        write_file << lines1[i] << endl;
    }
    write_file.close();
    std::cout << "Car rented successfully.\n\n";
    system("pause");
    std::cout << endl;

    return;
}

int return_request(string ID, string file_name, float x)
{
    vector<string> model_cars;
    ifstream inputFile;
    inputFile.open("Car.csv");
    string line = "";
    int flag = 0;
    std::cout << "Showing Models of cars currently rented..." << endl
              << endl;
    while (getline(inputFile, line))
    {

        stringstream inputString(line);
        string Model;
        string Condition;
        int Is_rented;
        string renter_ID;
        float rent_price;
        string due_date;
        string temp = "";

        getline(inputString, Model, ',');
        getline(inputString, Condition, ',');
        getline(inputString, temp, ',');
        Is_rented = stoi(temp);
        temp = "";
        getline(inputString, renter_ID, ',');
        getline(inputString, temp, ',');
        rent_price = stof(temp);
        temp = "";
        getline(inputString, due_date, '\n');

        if (renter_ID == ID)
        {
            flag++;
            model_cars.push_back(Model);
            std::cout << flag << ". Model : " << Model << ", Rent price(per day) : " << rent_price * x << endl;
        }
        line = "";
    }
    if (flag == 0)
    {
        std::cout << "Currently no car rented by you" << endl
                  << endl;
        system("pause");
        std::cout << endl;
        return 10;
    }
    int n = flag;
    n++;
    std::cout << n << ". Previous menu\n";
    n++;
    std::cout << n << ". Exit\n";
select_car:
    int num;
    std::cin >> num;
    if (num < 0 || num > n)
    {
        std::cout << "INVALID INPUT\nRe-enter the number\n";
        system("pause");
        std::cout << endl;
        goto select_car;
    }
    else if (num == n - 1)
    {
        std::cout << endl;
        return 10;
    }
    else if (num == n)
    {
        std::cout << "\nClosing...\n\n";
        return 0;
    }
    int extra_days;
    string condition;
    std::cout << "Enter the number of days after due date. if you are returning it before due date enter 0: ";
    std::cin >> extra_days;
    std::cout << "Enter current condition of cars(good/average/bad): ";
    std::cin >> condition;
    float additional_fine = 50.0 * extra_days * x;
    std::cout << "Returning car...\n";
    fstream read_file;
    read_file.open(file_name);
    if (read_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 10;
    }
    vector<string> lines;
    string line1;
    while (getline(read_file, line1))
    {
        lines.push_back(line1);
        stringstream inputString(line1);
        string curr_ID;
        getline(inputString, curr_ID, ',');
        if (curr_ID == ID)
        {
            string name;
            string password;
            int rented_cars;
            float fine;
            string record;
            int car_limit;
            string temp = "";
            getline(inputString, name, ',');
            getline(inputString, password, ',');
            getline(inputString, temp, ',');
            rented_cars = stoi(temp);
            temp = "";
            getline(inputString, temp, ',');
            fine = stof(temp);
            temp = "";
            getline(inputString, record, ',');
            getline(inputString, temp, ',');
            car_limit = stoi(temp);
            temp = "";
            rented_cars--;
            fine = fine + additional_fine;
            if (extra_days != 0)
            {
                if (car_limit == 5)
                {
                    car_limit--;
                    record = "satisfactory";
                }
                else if (car_limit == 4)
                {
                    car_limit--;
                    record = "average";
                }
                else if (car_limit == 3)
                {
                    car_limit--;
                    record = "below_average";
                }
                else if (car_limit == 2)
                {
                    car_limit--;
                    record = "unsatisfactory";
                }
            }
            else if (extra_days == 0)
            {
                if (car_limit == 1)
                {
                    car_limit++;
                    record = "below_avergae";
                }
                else if (car_limit == 2)
                {
                    car_limit++;
                    record = "average";
                }
                else if (car_limit == 3)
                {
                    car_limit++;
                    record = "satisfactory";
                }
                else if (car_limit == 4)
                {
                    car_limit++;
                    record = "excellent";
                }
            }
            // update record and car limit here
            line1 = ID + "," + name + "," + password + "," + to_string(rented_cars) + "," + to_string(fine) + "," + record + "," + to_string(car_limit);
            lines.pop_back();
            lines.push_back(line1);
            line1 = "";
        }
    }
    read_file.close();

    ofstream write_file;
    write_file.open(file_name);
    if (write_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 10;
    }
    for (int i = 0; i < lines.size(); i++)
    {
        write_file << lines[i] << endl;
    }
    write_file.close();

    // update car
    read_file.open("Car.csv");
    if (read_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 10;
    }
    vector<string> lines1;
    string line2 = "";
    while (getline(read_file, line2))
    {
        lines1.push_back(line2);
        stringstream inputString(line2);
        string curr_ID;
        getline(inputString, curr_ID, ',');
        if (curr_ID == model_cars[num - 1])
        {
            string prev_cond;
            string is_rented;
            string renter_id;
            string price;
            string due_date;
            getline(inputString, prev_cond, ',');
            getline(inputString, is_rented, ',');
            getline(inputString, renter_id, ',');
            getline(inputString, price, ',');
            getline(inputString, due_date, '\n');
            line2 = curr_ID + "," + condition + ",0,NULL," + price + ",NULL";
            lines1.pop_back();
            lines1.push_back(line2);
            line2 = "";
        }
    }
    read_file.close();

    write_file.open("Car.csv");
    if (write_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 10;
    }
    for (int i = 0; i < lines1.size(); i++)
    {
        write_file << lines1[i] << endl;
    }
    write_file.close();
    std::cout << "Car returned successfully.\n\n";
    system("pause");
    std::cout << endl;
    return 10;
}

int browse_cars(float x, string ID)
{
browse_menu:
    std::cout << "1. View all available cars\n2. View particular Car\n3. View Currently rented cars\n4. Previous menu\n5. Exit\n";
    string n;
    std::cin >> n;
    std::cout << "\n";
    string model_no = "";
    if (n == "2")
    {
        std::cout << "Enter model of the car which you want to view: ";
        std::cin >> model_no;
        std::cout << endl
                  << endl;
    }
    else if (n == "4")
    {
        return 4;
    }
    else if (n == "5")
    {
        std::cout << "Closing..." << endl
                  << endl;
        return 0;
    }
    else if (n != "1" && n != "2" && n != "3" && n != "4" && n != "5")
    {
        std::cout << "INVALID INPUT" << endl
                  << endl;
        system("pause");
        std::cout << endl;
        goto browse_menu;
    }

    ifstream inputFile;
    inputFile.open("Car.csv");
    string line = "";
    int flag = 0;
    int no_lines = 0;
    int num = 0;
    std::cout << "Showing cars..." << endl
              << endl;
    while (getline(inputFile, line))
    {
        no_lines++;
        stringstream inputString(line);
        string Model;
        string Condition;
        int Is_rented;
        string renter_ID;
        float rent_price;
        string due_date;
        string temp = "";

        getline(inputString, Model, ',');
        getline(inputString, Condition, ',');
        getline(inputString, temp, ',');
        Is_rented = stoi(temp);
        temp = "";
        getline(inputString, renter_ID, ',');
        getline(inputString, temp, ',');
        rent_price = stof(temp);
        temp = "";
        getline(inputString, due_date, '\n');
        if (n == "2")
        {
            if (model_no == Model)
            {
                if (renter_ID == ID)
                {
                    flag = 1;
                    std::cout << "Model : " << Model << ", Condition : " << Condition << ", Currently rented by you, Rent price(per day) : " << rent_price * x << ", Due date : " << due_date << endl;
                    line = "";
                }
                else
                {
                    flag = 1;
                    std::cout << "Model : " << Model << ", Condition: " << Condition;
                    if (Is_rented == 0)
                        std::cout << ", Available for rent";
                    else
                        std::cout << ", Car is rented by some other Customer/Employee, Expected date after which car will be available : " << due_date;
                    std::cout << ", rent price(per day) : " << rent_price * x;
                    std::cout << endl;
                    line = "";
                }
                return 0;
            }
        }
        else if (n == "1")
        {
            if (Is_rented == 0)
            {
                num++;
                std::cout << "Model : " << Model << ", Condition: " << Condition;
                std::cout << ", rent price(per day) : " << rent_price * x;
                std::cout << endl;
                line = "";
            }
        }
        else if (n == "3")
        {
            if (renter_ID == ID)
            {
                flag = 1;
                std::cout << "Model : " << Model << ", Condition : " << Condition << ", Rent price(per day) : " << rent_price * x << ", Due date : " << due_date << endl
                          << endl;
            }
        }
    }
    if (no_lines == 0 && n == "1")
    {
        std::cout << "Car database is empty" << endl;
    }
    else if (n == "2" && flag == 0)
    {
        std::cout << "Car with Model " << model_no << " does not exist in database" << endl;
    }
    else if (n == "3" && flag == 0)
    {
        std::cout << "No car currently rented" << endl;
    }
    else if (num == 0 && n != "3")
    {
        std::cout << "No cars available for rent" << endl;
    }
    system("pause");
    std::cout << endl;

    return 4;
}

void fine(string file_name, string id)
{
    ifstream inputFile;
    inputFile.open(file_name);
    string line = "";
    int flag = 0;
    while (getline(inputFile, line))
    {
        stringstream inputString(line);
        string ID;
        string Name;
        string Password;
        int rented_cars;
        float fine;
        string record;
        int car_limit;
        string temp = "";

        getline(inputString, ID, ',');
        getline(inputString, Name, ',');
        getline(inputString, Password, ',');
        getline(inputString, temp, ',');
        rented_cars = stoi(temp);
        temp = "";
        getline(inputString, temp, ',');
        fine = stof(temp);
        temp = "";
        getline(inputString, record, ',');
        getline(inputString, temp, '\n');
        car_limit = stoi(temp);
        temp = "";

        if (ID == id)
        {
            std::cout << "Your total fine is " << fine << endl;
            break;
        }
        line = "";
    }
    system("pause");
    std::cout << endl;
    return;
}

class Manager : private User
{
public:
    int add();
    int update();
    int delete_record();
    int cars_info();
    int members_info();
    friend int search_car(string model_no);
    friend int search_member(string file_name, string member_id);
    friend vector<string> search_id(string id_no, string file_name);
    friend vector<string> search_model(string model);
    friend vector<string> search_pass(string password, string file_name);
};

int Manager::add()
{
label2:
    string n;
    std::cout << "1. Add Customer\n2. Add Employee\n3. Add Car\n4. Previous menu\n5. Exit\n";
    std::cin >> n;
    std::cout << endl;
    // Add in Car database
    if (n == "3")
    {
        string Model;
        string Condition;
        int Is_rented;
        string renter_ID;
        float Rent_Price;
        string due_date;
        std::cout << "Enter Model: ";
        std::cin >> Model;
        if (search_car(Model) == 1)
        {
            std::cout << "given record already exists in database" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto label2;
        }
        std::cout << "Enter Car Condition(good/average/bad): ";
        std::cin >> Condition;
        std::cout << "Enter rent price of car(per day): ";
        std::cin >> Rent_Price;
        Is_rented = 0;
        renter_ID = "NULL";
        due_date = "NULL";

        fstream fout;
        fout.open("Car.csv", ios::app);
        fout << Model << ","
             << Condition << ","
             << Is_rented << ","
             << renter_ID << ","
             << Rent_Price << ","
             << due_date
             << "\n";
        fout.close();
        std::cout << "\nAdded successfully\n\n";
        system("pause");
        std::cout << endl;
    }

    // Add in Customer and Employee database
    else if (n == "1" | n == "2")
    {
        string file_name = "";
        if (n == "1")
            file_name = "Customer.csv";
        else if (n == "2")
            file_name = "Employee.csv";
        string id;
        string name;
        string password;
        int no_rented_cars;
        int fine_due;
        string record;
        int car_limit;
        std::cout << "Enter ID: ";
        std::cin >> id;
        if (search_member(file_name, id) == 1)
        {
            std::cout << "given record already exists in database" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto label2;
        }
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter Password: ";
        std::cin >> password;
        no_rented_cars = 0;
        fine_due = 0;
        record = "average";
        car_limit = 3;
        std::cout << "\n\n";

        fstream fout;
        fout.open(file_name, ios::app);
        fout << id << ","
             << name << ","
             << password << ","
             << no_rented_cars << ","
             << fine_due << ","
             << record << ","
             << car_limit
             << "\n";
        fout.close();
        std::cout << "\nAdded successfully\n\n";
        system("pause");
        std::cout << endl;
    }

    else if (n == "4")
        return 4;
    else if (n == "5")
    {
        std::cout << "Closing...\n\n";
        return 0;
    }
    else
    {
        std::cout << "INVALID INPUT" << endl
                  << endl;
        system("pause");
        std::cout << endl;
        goto label2;
    }
    goto label2;
}

int Manager::update()
{
update_menu:
    string file_name = "";
    vector<string> mem_rec;
    vector<string> car_rec;
    std::cout << "1. Update Customer\n2. Update Employee\n3. Update Car\n4. Previous menu\n5. Exit\n";
    string num1;
    std::cin >> num1;
    string id = "";
    string model = "";
    if (num1 == "1")
    {
        file_name = "Customer.csv";
        std::cout << "\nEnter Customer ID whose record you want to update: ";
        std::cin >> id;
        mem_rec = search_id(id, file_name);
        if (mem_rec.size() == 0)
        {
            std::cout << "Customer with ID " << id << " doesn't exist in database\n\n";
            system("pause");
            std::cout << endl;
            goto update_menu;
        }
    }
    else if (num1 == "2")
    {
        file_name = "Employee.csv";
        std::cout << "\nEnter Employee ID whose record you want to update: ";
        std::cin >> id;
        mem_rec = search_id(id, file_name);
        if (mem_rec.size() == 0)
        {
            std::cout << "Employee with ID " << id << " doesn't exist in database\n\n";
            system("pause");
            std::cout << endl;
            goto update_menu;
        }
    }
    else if (num1 == "3")
    {
        file_name = "Car.csv";
        std::cout << "\nEnter Car model whose record you want to update: ";
        std::cin >> model;
        car_rec = search_model(model);
        if (car_rec.size() == 0)
        {
            std::cout << "Car with model " << model << " doesn't exist in database\n\n";
            system("pause");
            std::cout << endl;
            goto update_menu;
        }
    }
    else if (num1 == "4")
    {
        std::cout << endl
                  << endl;
        return 4;
    }
    else if (num1 == "5")
    {
        std::cout << "\nClosing...\n\n";
        return 0;
    }
    else if (num1 != "1" && num1 != "2" && num1 != "3" && num1 != "4" && num1 != "5")
    {
        std::cout << "\nINVALID  INPUT\n\n";
        system("pause");
        std::cout << endl;
        goto update_menu;
    }

    if (num1 == "3")
    {
        fstream read_file;
        read_file.open("Car.csv");
        if (read_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 4;
        }
        vector<string> lines;
        string line;
        while (getline(read_file, line))
        {
            lines.push_back(line);
            stringstream inputString(line);
            string curr_ID;
            getline(inputString, curr_ID, ',');
            if (curr_ID == model)
            {
                string condition;
                string is_rented;
                string renter;
                string price;
                string due_date;
                getline(inputString, condition, ',');
                getline(inputString, is_rented, ',');
                getline(inputString, renter, ',');
                getline(inputString, price, ',');
                getline(inputString, due_date, '\n');
                char choice;
                std::cout << "Do you want to update model?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter updated model of the car: ";
                    std::cin >> model;
                    if (car_rec[0] == model)
                        goto next;
                    else
                    {
                        if (search_car(model) == 1)
                        {
                            std::cout << "Model : " << model << " already taken\n\n";
                            system("pause");
                            std::cout << endl;
                            goto update_menu;
                        }
                    }
                }
            next:
                std::cout << "Do you want to change condition of the car?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter new condition of the car: ";
                    std::cin >> condition;
                }
                std::cout << "Do you want to update rent price(per day)?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter updated rent price(per day) of the car: ";
                    std::cin >> price;
                }
                line = model + "," + condition + "," + is_rented + "," + renter + "," + price + "," + due_date;
                lines.pop_back();
                lines.push_back(line);
                line = "";
            }
        }
        read_file.close();

        ofstream write_file;
        write_file.open("Car.csv");
        if (write_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 4;
        }
        for (int i = 0; i < lines.size(); i++)
        {
            write_file << lines[i] << endl;
        }
        write_file.close();
        std::cout << "\nCar record updated successfully\n\n";
        system("pause");
        std::cout << endl;
        return 4;
    }
    else if (num1 == "1" || num1 == "2")
    {
        int flag = 0;
        fstream read_file;
        read_file.open(file_name);
        if (read_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 4;
        }
        vector<string> lines;
        string line;
        while (getline(read_file, line))
        {
            lines.push_back(line);
            stringstream inputString(line);
            string curr_ID;
            getline(inputString, curr_ID, ',');
            if (curr_ID == id)
            {
                string name;
                string password;
                string rented_cars;
                string fine;
                string record;
                string temp = "";
                int car_limit;
                getline(inputString, name, ',');
                getline(inputString, password, ',');
                getline(inputString, rented_cars, ',');
                getline(inputString, fine, ',');
                getline(inputString, record, ',');
                getline(inputString, temp, '\n');
                car_limit = stoi(temp);
                temp = "";
                char choice;
                char ch_id;
                std::cout << "Do you want to change ID?(y/n): ";
                std::cin >> ch_id;
                if (ch_id == 'y')
                {
                    std::cout << "Enter updated ID: ";
                    std::cin >> id;
                    if (id == curr_ID)
                        goto member_next;
                    else
                    {
                        if (search_member(file_name, id) == 1)
                        {
                            std::cout << "ID : " << id << " already exists in database\n\n";
                            system("pause");
                            std::cout << endl;
                            goto update_menu;
                        }
                        flag = 1;
                    }
                }
            member_next:
                std::cout << "Do you want to change name?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter new name: ";
                    std::cin >> name;
                }
                std::cout << "Do you want to change password?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter new password: ";
                    std::cin >> password;
                    vector<string> pass_rec = search_pass(password, file_name);
                    if (password == mem_rec[2])
                        goto next2;
                    else if (pass_rec.size() != 0)
                    {
                        std::cout << "\nThis password is already taken\n\n";
                        system("pause");
                        std::cout << endl;
                        goto update_menu;
                    }
                }
            next2:
                std::cout << "Do you want to update fine?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter updated value of fine: ";
                    std::cin >> fine;
                }
                std::cout << "Do you want to change car_limit?(y/n): ";
                std::cin >> choice;
                if (choice == 'y')
                {
                    std::cout << "Enter new car limit(1 to 5): ";
                    std::cin >> car_limit;
                    int int_rented = stoi(rented_cars);
                    if (car_limit < int_rented)
                    {
                        std::cout << "\nValue of car limit can't be less then no of cars currently rented\n\n";
                        system("pause");
                        std::cout << endl;
                        goto update_menu;
                    }
                    if (car_limit == 1)
                        record = "unsatisfactory";
                    else if (car_limit == 2)
                        record = "below_average";
                    else if (car_limit == 3)
                        record = "average";
                    else if (car_limit == 4)
                        record = "satisfactory";
                    else if (car_limit == 5)
                        record = "excellent";
                    else
                    {
                        std::cout << "\nINVALID INPUT\n\n";
                        system("pause");
                        std::cout << endl;
                        goto update_menu;
                    }
                }

                line = id + "," + name + "," + password + "," + rented_cars + "," + fine + "," + record + "," + to_string(car_limit);
                lines.pop_back();
                lines.push_back(line);
                line = "";
            }
        }
        read_file.close();

        ofstream write_file;
        write_file.open(file_name);
        if (write_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 4;
        }
        for (int i = 0; i < lines.size(); i++)
        {
            write_file << lines[i] << endl;
        }
        write_file.close();

        if (flag == 1)
        {
            fstream read_file;
            read_file.open("Car.csv");
            if (read_file.fail())
            {
                std::cout << "Error opening file." << endl;
                return 4;
            }
            vector<string> lines1;
            string line1;
            while (getline(read_file, line1))
            {
                lines1.push_back(line1);
                stringstream inputString(line1);
                string model;
                string condition;
                string is_rented;
                string renter;
                string price;
                string due_date;
                getline(inputString, model, ',');
                getline(inputString, condition, ',');
                getline(inputString, is_rented, ',');
                getline(inputString, renter, ',');
                getline(inputString, price, ',');
                getline(inputString, due_date, '\n');
                if (renter == mem_rec[0])
                {
                    renter = id;
                }
                line1 = model + "," + condition + "," + is_rented + "," + renter + "," + price + "," + due_date;
                lines1.pop_back();
                lines1.push_back(line1);
                line1 = "";
            }
            read_file.close();

            ofstream write_file;
            write_file.open("Car.csv");
            if (write_file.fail())
            {
                std::cout << "Error opening file." << endl;
                return 4;
            }
            for (int i = 0; i < lines1.size(); i++)
            {
                write_file << lines1[i] << endl;
            }
            write_file.close();
        }
        std::cout << "\nrecord updated successfully...\n\n";
        system("pause");
        std::cout << endl;
        return 4;
    }
    return 4;
}

int Manager::delete_record()
{
delete_menu:
    string file_name = "";
    string n;
    std::cout << "1. Delete Customer record\n2. Delete Employee record\n3. Delete Car record\n4. Previous menu\n5. Exit\n";
    std::cin >> n;
    std::cout << endl;
    string ID;
    vector<string> deleted_record;
    // Delete Customer or Employee record
    if (n == "1" || n == "2")
    {
        if (n == "1")
            file_name = "Customer.csv";
        else if (n == "2")
            file_name = "Employee.csv";
        std::cout << "Enter ID whose record you want to delete: ";
        std::cin >> ID;
        if (search_member(file_name, ID) == 0)
        {
            std::cout << "Given ID " << ID << " doesn't exist in database" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            return 4;
        }
    }
    else if (n == "4")
    {
        return 4;
    }
    else if (n == "5")
    {
        std::cout << "\nClosing...\n\n";
        return 0;
    }
    else if (n != "1" && n != "2" && n != "3" && n != "4" && n != "5")
    {
        std::cout << "INVALID INPUT\n\n";
        system("pause");
        std::cout << endl;
        goto delete_menu;
    }
    // Delete Car record
    else if (n == "3")
    {
        file_name = "Car.csv";
        std::cout << "Enter Model of car whose record you want to delete: ";
        std::cin >> ID;
        if (search_car(ID) == 0)
        {
            std::cout << "Car with Model " << ID << " doesn't exist in database" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            return 0;
        }
    }
    else
    {
        std::cout << "INVALID INPUT";
        system("pause");
        std::cout << endl;
        return 0;
    }

    fstream read_file;
    read_file.open(file_name);
    if (read_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 0;
    }
    vector<string> lines;
    string line;
    int line_num = 0;
    while (getline(read_file, line))
    {
        lines.push_back(line);
        stringstream inputString(line);
        string curr_ID;
        getline(inputString, curr_ID, ',');
        if (curr_ID == ID)
        {
            deleted_record.push_back(curr_ID);
            string col2, col3, col4;
            getline(inputString, col2, ',');
            getline(inputString, col3, ',');
            getline(inputString, col4, ',');
            deleted_record.push_back(col2);
            deleted_record.push_back(col3);
            deleted_record.push_back(col4);
            lines.pop_back();
        }
        line_num++;
    }
    read_file.close();

    ofstream write_file;
    write_file.open(file_name);
    if (write_file.fail())
    {
        std::cout << "Error opening file." << endl;
        return 0;
    }
    for (int i = 0; i < lines.size(); i++)
    {
        write_file << lines[i] << endl;
    }
    write_file.close();

    if (n == "3" && deleted_record[2] != "0")
    {
        if (search_member("Customer.csv", deleted_record[3]) == 1)
            file_name = "Customer.csv";
        else if (search_member("Employee.csv", deleted_record[3]) == 1)
            file_name = "Employee.csv";
        fstream read_file;
        read_file.open(file_name);
        if (read_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 0;
        }
        vector<string> lines;
        string line;
        int line_num = 0;
        while (getline(read_file, line))
        {
            lines.push_back(line);
            stringstream inputString(line);
            string ID;
            string Name;
            string password;
            int rented_cars;
            string fine;
            string customer_record;
            string car_limit;
            string temp = "";
            getline(inputString, ID, ',');
            getline(inputString, Name, ',');
            getline(inputString, password, ',');
            getline(inputString, temp, ',');
            rented_cars = stoi(temp);
            temp = "";
            getline(inputString, fine, ',');
            getline(inputString, customer_record, ',');
            getline(inputString, car_limit, '\n');
            if (ID == deleted_record[3])
            {
                rented_cars--;
                string str_cars = to_string(rented_cars);
                line = ID + "," + Name + "," + password + "," + str_cars + "," + fine + "," + customer_record + "," + car_limit;
                lines.pop_back();
                lines.push_back(line);
                line = "";
            }
        }
        read_file.close();

        ofstream write_file;
        write_file.open(file_name);
        if (write_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 0;
        }
        for (int i = 0; i < lines.size(); i++)
        {
            write_file << lines[i] << endl;
        }
        write_file.close();
    }
    else if ((n == "1" || n == "2") && deleted_record[3] != "0")
    {
        fstream read_file;
        read_file.open("Car.csv");
        if (read_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 0;
        }
        vector<string> lines;
        string line;
        int line_num = 0;
        int idx = 0;
        while (getline(read_file, line))
        {
            lines.push_back(line);
            stringstream inputString(line);
            string Model;
            string Condition;
            int Is_rented;
            string renter_ID;
            string rent_price;
            string due_date;
            string temp = "";

            getline(inputString, Model, ',');
            getline(inputString, Condition, ',');
            getline(inputString, temp, ',');
            Is_rented = stoi(temp);
            temp = "";
            getline(inputString, renter_ID, ',');
            getline(inputString, rent_price, ',');
            getline(inputString, due_date, '\n');
            if (renter_ID == deleted_record[0])
            {
                Is_rented = 0;
                renter_ID = "NULL";
                due_date = "NULL";
                line = Model + "," + Condition + ",0," + renter_ID + "," + rent_price + "," + due_date;
                lines.pop_back();
                lines.push_back(line);
                line = "";
            }
        }
        read_file.close();

        ofstream write_file;
        write_file.open("Car.csv");
        if (write_file.fail())
        {
            std::cout << "Error opening file." << endl;
            return 0;
        }
        for (int i = 0; i < lines.size(); i++)
        {
            write_file << lines[i] << endl;
        }
        write_file.close();
    }
    system("pause");
    std::cout << endl;
    return 4;
}
int Manager::cars_info()
{
carinfo_menu:
    std::cout << "1. View all Cars record\n2. View particular Car record\n3. Previous menu\n4. Exit\n";
    string n;
    std::cin >> n;
    std::cout << "\n";
    string model_no = "";
    if (n == "2")
    {
        std::cout << "Enter model no of the car which you want to view: ";
        std::cin >> model_no;
    }
    else if (n == "3")
    {
        return 3;
    }
    else if (n == "4")
    {
        std::cout << "Closing...\n\n";
        return 0;
    }
    else if (n != "1" && n != "2" && n != "3" && n != "4")
    {
        std::cout << "INVALID INPUT" << endl
                  << endl;
        system("pause");
        std::cout << endl;
        goto carinfo_menu;
    }

    ifstream inputFile;
    inputFile.open("Car.csv");
    string line = "";
    int flag = 0;
    int no_lines = 0;
    std::cout << "Showing Car database..." << endl
              << endl;
    while (getline(inputFile, line))
    {
        no_lines++;
        stringstream inputString(line);
        string Model;
        string Condition;
        int Is_rented;
        string renter_ID;
        float rent_price;
        string due_date;
        string temp = "";

        getline(inputString, Model, ',');
        getline(inputString, Condition, ',');
        getline(inputString, temp, ',');
        Is_rented = stoi(temp);
        temp = "";
        getline(inputString, renter_ID, ',');
        getline(inputString, temp, ',');
        rent_price = stof(temp);
        temp = "";
        getline(inputString, due_date, '\n');
        if (n == "2")
        {
            if (model_no == Model)
            {
                flag = 1;
                std::cout << "Model : " << Model << ", Condition: " << Condition;
                if (Is_rented == 0)
                    std::cout << ", Available to rent";
                else
                    std::cout << ", rented to Customer/Employee with ID : " << renter_ID;
                std::cout << ", rent price(per day) : " << rent_price;
                if (due_date != "NULL")
                    cout << ", due date : " << due_date;
                std::cout << endl;
                line = "";
                std::cout << endl
                          << endl;
                goto carinfo_menu;
            }
        }
        else if (n == "1")
        {
            std::cout << "Model : " << Model << ", Condition: " << Condition;
            if (Is_rented == 0)
                std::cout << ", Available to rent";
            else
                std::cout << ", rented to Customer/Employee with ID : " << renter_ID;
            std::cout << ", rent price(per day) : " << rent_price;
            if (due_date != "NULL")
                cout << ", due date : " << due_date;
            std::cout << endl;
            line = "";
        }
    }
    if (no_lines == 0 && n == "1")
    {
        std::cout << "Car database is empty" << endl;
        system("pause");
        std::cout << endl;
    }
    else if (n == "2" && flag == 0)
    {
        std::cout << "Car with Model " << model_no << " does not exist in database" << endl;
        system("pause");
        std::cout << endl;
    }
    system("pause");
    std::cout << endl;
    return 3;
}

int Manager::members_info()
{
meminfo_menu:
    std::cout << "1. View Customer data\n2. View Employee data\n3. Previous menu\n4. Exit\n";
    string num1;
    string num2;
    string file_name;
    string id_no;
    std::cin >> num1;
    std::cout << endl;
    if (num1 == "1")
    {
    Cus_menu:
        file_name = "Customer.csv";
        std::cout << "1. View all customers data\n2. View particular customer data\n3. Previous menu\n4. Exit\n";
        std::cin >> num2;
        std::cout << endl;
        if (num2 == "2")
        {
            std::cout << "Enter Customer ID whose record you want to view: ";
            std::cin >> id_no;
            std::cout << endl;
        }
        else if (num2 != "1" && num2 != "2" && num2 != "3" && num2 != "4")
        {
            std::cout << "INVALID INPUT" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto Cus_menu;
        }
        else if (num2 == "3")
            goto meminfo_menu;
        else if (num2 == "4")
        {
            std::cout << "\nClosing...\n\n";
            return 0;
        }
        std::cout << endl;
        std::cout << "Showing customer database..." << endl
                  << endl;
    }
    else if (num1 == "2")
    {
    Emp_menu:
        file_name = "Employee.csv";
        std::cout << "1. View all employees data\n2. View particular employee data\n3. Previous menu\n4. Exit\n";
        std::cin >> num2;
        std::cout << endl;
        if (num2 == "2")
        {
            std::cout << "Enter Employee ID whose record you want to view: ";
            std::cin >> id_no;
            std::cout << endl;
        }
        else if (num2 != "1" && num2 != "2" && num2 != "3" && num2 != "4")
        {
            std::cout << "INVALID INPUT" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto Emp_menu;
        }
        else if (num2 == "3")
            goto meminfo_menu;
        else if (num2 == "4")
        {
            std::cout << "\nClosing\n\n";
            return 0;
        }
        std::cout << endl;
        std::cout << "Showing customer database..." << endl
                  << endl;
    }
    else if (num1 == "3")
        return 3;
    else if (num1 == "4")
    {
        std::cout << "\nClosing...\n\n";
        return 0;
    }
    else
    {
        std::cout << "INVALID INPUT" << endl
                  << endl;
        system("pause");
        std::cout << endl;
        goto meminfo_menu;
    }

    ifstream inputFile;
    inputFile.open(file_name);
    string line = "";
    int flag = 0;
    int no_of_line = 0;

    while (getline(inputFile, line))
    {
        no_of_line++;
        stringstream inputString(line);
        string ID;
        string Name;
        string Password;
        int rented_cars;
        float fine;
        string record;
        int car_limit;
        string temp = "";

        getline(inputString, ID, ',');
        getline(inputString, Name, ',');
        getline(inputString, Password, ',');
        getline(inputString, temp, ',');
        rented_cars = stoi(temp);
        temp = "";
        getline(inputString, temp, ',');
        fine = stof(temp);
        temp = "";
        getline(inputString, record, ',');
        getline(inputString, temp, '\n');
        car_limit = stoi(temp);
        temp = "";

        if (num2 == "2")
        {
            if (id_no == ID)
            {
                flag == 1;
                cout << "ID : " << ID << ", Name : " << Name << ", Password : " << Password << ", Number of cars rented : " << rented_cars << ", fine : " << fine << ", record : " << record << ", Maximum number of cars that can be rennted : " << car_limit << endl
                     << endl;
                return 0;
            }
        }
        else
        {
            cout << "ID : " << ID << ", Name : " << Name << ", Password : " << Password << ", Number of cars rented : " << rented_cars << ", fine : " << fine << ", record : " << record << ", Maximum number of cars that can be rennted : " << car_limit << endl;
        }
        line = "";
    }
    if (no_of_line == 0 && num2 == "1")
    {
        std::cout << "Database is empty" << endl;
        system("pause");
        std::cout << endl;
    }
    else if (num2 == "2" && flag == 0)
    {
        if (num1 == "1")
        {
            std::cout << "Customer with ID " << id_no << " does not exist in database" << endl;
            system("pause");
            std::cout << endl;
        }
        else if (num1 == "2")
        {
            std::cout << "Employee with ID " << id_no << " does not exist in database" << endl;
            system("pause");
            std::cout << endl;
        }
    }
    system("pause");
    std::cout << endl;
    return 0;
}

int main()
{
label1:
    cout << "1. Customer\n2. Employee\n3. Manager\n4. Exit\n";
    string n;
    cin >> n;
    cout << endl;
    string user_id;
    string password;

    // Customer
    if (n == "1")
    {
    Customer_menu:
        std::cout << "Customer\n1. Already has an account\n2. Create new account\n3. Previous Menu\n4. Exit\n";
        string num1;
        std::cin >> num1;
        std::cout << endl;
        if (num1 == "1")
        {
            std::cout << "Enter your Userid: ";
            cin >> user_id;
            std::cout << "Enter your Password: ";
            cin >> password;
            std::cout << endl;
            vector<string> check_idpass = search_id(user_id, "Customer.csv");
            if (check_idpass.size() == 0)
            {
                std::cout << "INVALID userid" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Customer_menu;
            }
            else if (check_idpass[2] != password)
            {
                std::cout << "WRONG Password" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Customer_menu;
            }
            else if (check_idpass[2] == password)
            {
                std::cout << "Logging in..." << endl
                          << endl;
                Customer cus;
            loggedin_menu:
                std::cout << "1. Browse Cars\n2. View fine\n3. Return Car\n4. Request a car for rent\n5. Logout\n6. Exit\n";
                string num2;
                std::cin >> num2;
                std::cout << endl;
                if (num2 == "1")
                {
                    int a = browse_cars(1, user_id);
                    if (a == 4)
                        goto loggedin_menu;
                }
                else if (num2 == "2")
                {
                    fine("Customer.csv", user_id);
                    goto loggedin_menu;
                }
                else if (num2 == "3")
                {
                    int a = return_request(user_id, "Customer.csv", 1);
                    if (a == 10)
                        goto loggedin_menu;
                }
                else if (num2 == "4")
                {
                    rent_request("Customer.csv", user_id, 1);
                    goto loggedin_menu;
                }
                else if (num2 == "5")
                    goto Customer_menu;
                else if (num2 == "6")
                {
                    std::cout << "Closing...\n\n";
                    return 0;
                }
                else
                {
                    std::cout << "INVALID INPUT" << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto loggedin_menu;
                }
            }
        }
        else if (num1 == "2")
        {
            string confirm_password;
            std::cout << "Enter New userid: ";
            std::cin >> user_id;
            vector<string> check_id2 = search_id(user_id, "Customer.csv");
            if (check_id2.size() != 0)
            {
                std::cout << user_id << " already taken" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Customer_menu;
            }
            else
            {
            Customer_password:
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Confirm password: ";
                std::cin >> confirm_password;
                if (password != confirm_password)
                {
                    std::cout << "Password didn't match" << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto Customer_password;
                }
                else
                {
                    vector<string> check_pass = search_pass(password, "Customer.csv");
                    if (check_pass.size() != 0)
                    {
                        std::cout << "Given password already taken" << endl
                                  << endl;
                        system("pause");
                        std::cout << endl;
                        goto Customer_menu;
                    }
                    else
                    {
                        string name;
                        std::cout << "Enter your Name: ";
                        std::cin >> name;
                        std::cout << "Creating Account...";
                        int no_rented_cars = 0;
                        int fine_due = 0;
                        string record = "average";
                        int car_limit = 3;
                        std::cout << "\n\n";

                        fstream fout;
                        fout.open("Customer.csv", ios::app);
                        fout << user_id << ","
                             << name << ","
                             << password << ","
                             << no_rented_cars << ","
                             << fine_due << ","
                             << record << ","
                             << car_limit
                             << "\n";
                        fout.close();
                    }
                    std::cout << "Account created successfully..." << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto Customer_menu;
                }
            }
        }
        else if (num1 == "3")
            goto label1;
        else if (num1 == "4")
        {
            std::cout << "Closing...\n\n";
            return 0;
        }
        else
        {
            std::cout << "INVALID INPUT" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto Customer_menu;
        }
    }

    // Employee
    else if (n == "2")
    {
    Employee_menu:
        std::cout << "Employee\n1. Already has an account\n2. Create new account\n3. Previous Menu\n4. Exit\n";
        string num3;
        std::cin >> num3;
        std::cout << endl;
        if (num3 == "1")
        {
            std::cout << "Enter your Userid: ";
            cin >> user_id;
            std::cout << "Enter your Password: ";
            cin >> password;
            std::cout << endl;
            vector<string> check_idpass_man = search_id(user_id, "Employee.csv");
            if (check_idpass_man.size() == 0)
            {
                std::cout << "INVALID userid" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Employee_menu;
            }
            else if (check_idpass_man[2] != password)
            {
                std::cout << "WRONG Password" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Employee_menu;
            }
            else if (check_idpass_man[2] == password)
            {
                std::cout << "Logging in..." << endl
                          << endl;
                Manager man;
            Man_loggedin_menu:
                std::cout << "1. Browse Cars\n2. View fine\n3. Return Car\n4. Request a car for rent\n5. Logout\n6. Exit\n";
                string num4;
                std::cin >> num4;
                std::cout << endl;
                if (num4 == "1")
                {
                    int a = browse_cars(1, user_id);
                    if (a == 4)
                        goto Man_loggedin_menu;
                }
                else if (num4 == "2")
                {
                    fine("Employee.csv", user_id);
                    goto Man_loggedin_menu;
                }
                else if (num4 == "3")
                {
                    int a = return_request(user_id, "Employee.csv", 0.85);
                    if (a == 10)
                        goto Man_loggedin_menu;
                }
                else if (num4 == "4")
                {
                    rent_request("Employee.csv", user_id, 0.85);
                    goto Man_loggedin_menu;
                }
                else if (num4 == "5")
                    goto Employee_menu;
                else if (num4 == "6")
                {
                    std::cout << "Closing...\n\n";
                    return 0;
                }
                else
                {
                    std::cout << "INVALID INPUT" << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto Man_loggedin_menu;
                }
            }
        }
        else if (num3 == "2")
        {
            string confirm_password;
            std::cout << "Enter New userid: ";
            std::cin >> user_id;
            vector<string> check_id2_man = search_id(user_id, "Employee.csv");
            if (check_id2_man.size() != 0)
            {
                std::cout << user_id << " already taken" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto Employee_menu;
            }
            else
            {
            Employee_password:
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Confirm password: ";
                std::cin >> confirm_password;
                if (password != confirm_password)
                {
                    std::cout << "Password didn't match" << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto Employee_password;
                }
                else
                {
                    vector<string> check_pass_man = search_pass(password, "Employee.csv");
                    if (check_pass_man.size() != 0)
                    {
                        std::cout << "Given password already taken" << endl
                                  << endl;
                        system("pause");
                        std::cout << endl;
                        goto Employee_menu;
                    }
                    else
                    {
                        string name;
                        std::cout << "Enter your Name: ";
                        std::cin >> name;
                        std::cout << "Creating Account...";
                        int no_rented_cars = 0;
                        int fine_due = 0;
                        string record = "average";
                        int car_limit = 3;
                        std::cout << "\n\n";

                        fstream fout;
                        fout.open("Employee.csv", ios::app);
                        fout << user_id << ","
                             << name << ","
                             << password << ","
                             << no_rented_cars << ","
                             << fine_due << ","
                             << record << ","
                             << car_limit
                             << "\n";
                        fout.close();
                    }
                    std::cout << "Account created successfully..." << endl
                              << endl;
                    system("pause");
                    std::cout << endl;
                    goto Employee_menu;
                }
            }
        }
        else if (num3 == "3")
            goto label1;
        else if (num3 == "4")
        {
            std::cout << "Closing...\n\n";
            return 0;
        }
        else
        {
            std::cout << "INVALID INPUT" << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto Employee_menu;
        }
    }

    // Manager
    else if (n == "3")
    {
        std::cout << "Enter your Userid: ";
        cin >> user_id;
        std::cout << "Enter your Password: ";
        cin >> password;
        if (user_id == "Indranilshah" && password == "CS253")
        {
            std::cout << "Logging in..." << endl
                      << endl;
            Manager head;
        label3:
            std::cout << "Manager\n1. Add Car/Customer/Employee\n2. Update Car/Customer/Employee\n3. Delete Car/Customer/Employee record\n4. View Car info\n5. View Customer/Employee information\n6. Logout\n7. Exit\n";
            string n;
            std::cin >> n;
            std::cout << endl;
            if (n == "1")
            {
                int num = head.add();
                if (num == 4)
                    goto label3;
            }
            else if (n == "2")
            {
                int a = head.update();
                if (a == 4)
                    goto label3;
            }
            else if (n == "3")
            {
                int a = head.delete_record();
                if (a == 4)
                    goto label3;
            }
            else if (n == "4")
            {
                int num = head.cars_info();
                if (num == 3)
                    goto label3;
            }
            else if (n == "5")
            {
                int a = head.members_info();
                if (a == 3)
                    goto label3;
            }
            else if (n == "6")
                goto label1;
            else if (n == "7")
            {
                std::cout << "Closing..." << endl
                          << endl;
                return 0;
            }
            else
            {
                std::cout << "INVALID INPUT" << endl
                          << endl;
                system("pause");
                std::cout << endl;
                goto label3;
            }
        }
        else
        {
            std::cout << "Wrong userid and password." << endl
                      << endl;
            system("pause");
            std::cout << endl;
            goto label1;
        }
    }

    // Exit
    else if (n == "4")
    {
        cout << "Closing...\n\n";
        return 0;
    }

    // invalid input
    else
    {
        cout << "INVALID INPUT\n\n";
        system("pause");
        std::cout << endl;
        goto label1;
    }

    return 0;
}