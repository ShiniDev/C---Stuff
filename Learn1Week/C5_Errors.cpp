#include <std_lib_facilities.h>
#include <stdint.h>
#include <strings.h>
int area(int,int);
int framed_area(int,int);
bool vector_contains_string(vector<string>, string);

void compute_area()
{
    try{
        int a = area(1000000000,1000000000);
    }catch(exception& e)
    {
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return;
    }catch(...){
        cerr << "Unknown exception!\n";
        keep_window_open();
        return;
    }
    keep_window_open();
}
int area(int length,int width)
{
    if(length<=0||width<=0)error("Non-positive value for 'area()' function");
    int a = length*width;
    if(a<=0)error("area()post-condition");
    return length*width;
}
int framed_area(int length,int width)
{
    return area(length-2,width-2);
}
void temperature()
{
    double temp = 0;
    double sum = 0;
    double high_temp = -89.2;//Lowest Temperature ever recorded on Earth
    double low_temp = 56.7;//Highest Temperature ever recorded on Earth
    int value_count = 0;
    while(cin>>temp){
        ++value_count;
        sum += temp;
        if(temp<low_temp)low_temp=temp;
        if(temp>high_temp)high_temp=temp;
    }
    cout << "Highest temperature: " << high_temp<< endl;
    cout << "Lowest temperature: " << low_temp << endl;
    cout << "Average temperature: " << sum/value_count << endl;
}
void c5_drill()//To improve the skill of debugging
{
    try{
        cout << "[1]Success!\n";
        cout << "[2]Success!\n";
        cout << "[3]Success!" << '\n';
        cout << "[4]Success!" << endl;
        int res = 7 ;vector<int>v(10);v[5]=res;cout << "[5]Success!\n";
        vector<int>v1(10);v1[5]=7;if (v1[5]==7) cout << "[6]Success!\n";
        if(true)cout << "[7]Success!\n";else cout << "Fail!\n" ;
        bool c = false; if (!(c)) cout << "[8]Success!\n"; else cout << "Fail!\n" ;
        string s = "ape"; bool c1 = "fool">s; if (c1) cout << "[9]Success!\n";
        string s1 = "ape"; if (s1=="ape") cout << "[10]Success!\n";
        string s2 = "ape"; if (s2=="ape") cout << "[11]Success!\n";
        string s3 = "ape"; if (s3+"fool" == "apefool") cout << "[12]Success!\n";
        vector<char> v2(5);for(int i=0; i<v2.size(); ++i)cout << "[13]Success!\n";
        vector<char> v3(5);for(int i=0; i<v3.size(); ++i)cout << "[14]Success!\n";
        string s4 = "[15]Success!\n" ;for(int i=0;i<s4.length(); ++i) cout << s4.at(i);
        if (true)cout << "[16]Success!\n" ; else cout << "Fail!\n " ;
        int x = 2000; char cha1 = x;char cha2 = x; if (cha1==cha2) cout << "[17]Success!\n" ;
        string s5 = "[18]Success!\n"; for(int i=0; i<s5.length(); ++i) cout << s5.at(i) ;
        vector<string> v4(5);for(int i=0; i<v4.size(); ++i) ; cout << "[19]Success!\n" ;
        int i=0;int j=9;while(i<10){++i;if(j<i)cout << "[20]Success!\n";}
        int x1=2; double d1 = 5.0/(x1-1); if (d1-0.5==2*x1+0.5) cout << "[21]Success!\n";
        string s6 = "[22]Success!\n"; for (int i=0; i<s6.length(); ++i) cout << s6.at(i);
        int i1=0;int j1=9;while (i1<10){++i1; if (j1<i1) cout << "[23]Success!\n";}
        int x2 = 4; double d2 = 5.0/(x2-2); if (d2==2*x2+0.5-6) cout << "[24]Success!\n";
        cout << "[25]Success!\n";
        keep_window_open();
        return;
    }catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return;
    }catch(...){
        cerr << "Unknown exception!\n";
        keep_window_open();
        return;
    }
}
double ctok(double c)//Converts Celcius to Kelvin
{
    double k = c + 273.15;
    if(c<-273.15||k<0)error("Temperature can't go below absolute zero");
    if(c>20000||k>20273.15)error("Temperature can't go higher than the hottest star");
    return k;
}
double ktoc(double k)//Converts Kelvin to Celcius
{
    double c = k - 273.15;
    if(c<-273.15||k<0)error("Temperature can't go below absolute zero");
    if(c>20000||k>20273.15)error("Temperature can't go higher than the hottest star");
    return c;
}
double ctof(double c)
{
    double f = (c*(9.0/5))+32;
    if(c<-273.15)error("Temperature can't go below absolute zero");
    if(c>20000)error("Temperature can't go higher than the hottest star");
    return f;
}
double ftoc(double f)
{
    double c = (f-32)*(5.0/9);
    if(c<-273.15)error("Temperature can't go below absolute zero");
    if(c>20000)error("Temperature can't go higher than the hottest star");
    return c;
}
void convert_temp()
{
    try{
        while(true){
            double celsius = 0;
            double kelvin = 0;
            double fahrenheit = 0;
            cout << "[1]Celsius to Kelvin\n[2]Celsius to Fahrenheit\n[3]Kelvin to Celsius\n[4]Fahrenheit to Celsius\n[5]Exit\n";
            char user_input = 'a';
            if(cin>>user_input){
            }else{
                cin.clear();
                cin.ignore(120, '\n');
                continue;
            }
            cout << endl;
            switch(user_input){
            case '1':
                while(true){
                    cout << "Input Celsius:\n";
                    if(cin >> celsius){
                        break;
                    }else{
                        cin.clear();
                        cin.ignore(120, '\n');
                        continue;
                    }
                }
                cout << celsius << " celsius is " << ctok(celsius) << " in kelvin.\n";
                break;
            case '3':
                while(true){
                    cout << "Input Kelvin:\n";
                    if(cin >> kelvin){
                        break;
                    }else{
                        cin.clear();
                        cin.ignore(120, '\n');
                        continue;
                    }
                }
                cout << kelvin << " kelvin is " << ktoc(kelvin) << " in celsius.\n";
                break;
            case '2':
                while(true){
                    cout << "Input Celsius:\n";
                    if(cin >> celsius){
                        break;
                    }else{
                        cin.clear();
                        cin.ignore(120, '\n');
                        continue;
                    }
                }
                cout << celsius << " celsius is " << ctof(celsius) << " in fahrenheit.\n";
                break;
            case '4':
                while(true){
                    cout << "Input Fahrenheit:\n";
                    if(cin >> fahrenheit){
                        break;
                    }else{
                        cin.clear();
                        cin.ignore(120, '\n');
                        continue;
                    }
                }
                cout << fahrenheit << " fahrenheit is " << ftoc(fahrenheit) << " in celsius.\n";
                break;
            case '5':
                return;
            default:
                cout << "Invalid Input\n";
            }
            if(user_input=='5'){
                return;
            }
            cout << endl;
        }
    }catch(exception& e){
        cerr << "Error: " << e.what() << '\n';
        keep_window_open();
        return;
    }catch(...){
        cerr << "Unknown exception!\n";
        keep_window_open();
        return;
    }

}
void quadratic_roots()
{
    try{
        cout << "Hi, I will solve your quadratic equation problem!\n";
        double a = 0,b = 0, c = 0;
        cout << "Input value for a\n";
        if(cin>>a){}else error("Letters are not allowed ^_^");
        cout << "Input value for b\n";
        if(cin>>b){}else error("Letters are not allowed ^_^");
        cout << "Input value for c\n";
        if(cin>>c){}else error("Letters are not allowed ^_^");
        //Formula: x = (-b-(sqrt((b*b)-4*a*c)))/(2*a)
        double root = (b*b)-(4*a*c);
        if(root<0)error("The equation has no real roots");
        double x = (-b+sqrt(root))/(2*a);
        double x1 =(-b-sqrt(root))/(2*a);
        cout << "x = " << x << " and " << "x = " << x1 << '\n';
    }catch (exception& e){
        cerr << "Error:" << e.what() << '\n';
        return;
    }catch(...){
        cerr << "Unknown exception\n";
        return;
    }

}
bool isNum(string num)
{
    int numholder;
    try{
        numholder = stoi(num);
        return true;
    }catch (exception& e){
        return false;
    }
}
void vector_sum()
{
    vector<double> numbers;
    vector<double> adjacent;
    cout << "Enter numbers(press '|' at prompt to stop)\n";
    string user_input = "??";
    double number = 0, sum = 0;
    while(true){
        cin >> user_input;
        if(user_input=="|")break;
        if(!(isNum(user_input))){
            cout << "Numbers only\n";
            continue;
        }
        number = stoi(user_input);
        numbers.push_back(number);
        cout << "Number added!\n";
    }
    cout << "Please specify how many numbers you will be adding starting from the first:\n";
    while(true){
        cin >> user_input;
        if(!(isNum(user_input))){
            cout << "Numbers only\n";
            continue;
        }
        number = stoi(user_input);
        if(number>numbers.size()){
            cout << "The number should not be greater on our gathered numbers\n";
            continue;
        }
        if(number<=0){
            cout << "The number should not be negative or 0\n";
            continue;
        }
        break;
    }
    cout << "The sum of the first " << number << " numbers: ";
    for(int i = 0;i<number;i++){
        sum += numbers[i];
        if(i+1==number){
            cout << "and " << numbers[i] << " is " << sum << '\n';
        }else cout << numbers[i] << ", ";
        if(i==0)adjacent.push_back(numbers[i] - numbers[numbers.size()-1]);
        if(i!=0)adjacent.push_back(numbers[i] - numbers[i-1]);
    }
    cout << "Adjacent values:\n";
    for(int i = 0;i<adjacent.size();i++){
        cout << "[" << i << "]\t" << adjacent[i] << '\n';
    }
}
void fibonacci()
{
    int64_t fibo = 0, p1 = 0, p2 = 0;

    while(true){
        fibo = p1+p2;
        if(fibo<0)break;
        if(fibo==0)p1++;
        p2=p1;
        p1=fibo;
        cout << fibo << '\n';
    }
}
bool contains_char(string guess,char a)
{
    for(int i = 0;i<guess.length();i++){
        if(guess.at(i)==a)return true;
    }
    return false;
}
bool vector_contains_string(vector<char> chars,char character)
{
    for(int i = 0;i<chars.size();i++){
        if(chars[i]==character)return true;
    }
    return false;
}
void bulls_cows()
{
    vector<char> filter;
    int bulls = 0, cows = 0;
    char seed = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    string guessstr = "2031";
    string user_input = "?";
    while(true){
        cout << "Input random number\n";
        cin >> user_input;
        if(!(isNum(user_input))){
            cout << "Numbers only\n";
            continue;
        }
        seed = stoi(user_input);
        break;
    }
    seed_randint(seed);
    while(true){
        cout << "Let's play bulls and cows!\n";
        cout << "[1]Play\n" << "[2]Exit\n";//Prompt
        cin >> user_input;
        if(user_input=="1"||user_input=="Play"||user_input=="play"){;
            guessstr = "";
            num1 = randint(97,122);num2 = randint(97,122);num3 = randint(97,122);num4 = randint(97,122);
            guessstr = to_string(num1)+to_string(num2)+to_string(num3)+to_string(num4);
            while(true){
                filter.clear();
                bulls=0;//Resets the values of both
                cows=0;
                cout << "Guess the 4 random letters!\nLowercase letters only\n";
                while(true){//Checks if the input is valid
                    cin >> user_input;
                    if(user_input=="cheat"){
                        cout << guessstr << '\n';
                        continue;
                    }
                    if((isNum(user_input))){
                        cout << "Characters only!\n";
                        continue;
                    }
                    if(user_input.length()!=4){
                        cout << "4 characters only!\n";
                        continue;
                    }
                    break;
                }
                for(int i = 0;i<guessstr.length();i++){
                    if(guessstr.at(i)==user_input.at(i)){
                        bulls++;
                    }else if(contains_char(guessstr,user_input.at(i))){
                        if(!(vector_contains_string(filter,user_input.at(i)))){
                            filter.push_back(user_input.at(i));
                            cows++;
                        }
                    }
                }
                if(user_input==guessstr){
                    cout << "Congratulations you guessed the right code!\n";
                    break;
                }else{
                    string pluralbull = "?";
                    string pluralcow = "?";
                    (bulls>1)? pluralbull = "Bulls":pluralbull = "Bull";
                    (cows>1)? pluralcow = "Cows":pluralcow = "Cow";
                    cout << bulls << " " << pluralbull << " and " << cows << " " << pluralcow << '\n';
                }
            }
        }else if(user_input=="2"||user_input=="Exit"||user_input=="exit"){
            cout << "Thanks for playing!\n";
            break;
        }else cout << "Invalid Input\n";

    }
}
bool isInput_A_Week_Day(string day){
    vector<string> days;
    days.push_back("Monday");
    days.push_back("Tuesday");
    days.push_back("Wednesday");
    days.push_back("Thursday");
    days.push_back("Friday");
    days.push_back("Saturday");
    days.push_back("Sunday");
    for(int i = 0;i<days.size();i++){
        if(strcasecmp(day.c_str(),days[i].c_str())==0 || strcasecmp(day.c_str(),days[i].substr(0,3).c_str())==0)return true;
    }
    return false;
}
void days_values()
{
    vector<string> week_days_input;
    vector<int> values;
    string input_value = "?";
    string input_day = "?";
    int value = 0;
    int rejected_count = 0;
    int sum = 0;
    while(values.size()<7){
        cout << "Please enter a day then followed by value, Tuesday 29\n";
        cin >> input_day;
        cin >> input_value;
        if(!(isInput_A_Week_Day(input_day))){
            cout << "Illegal Day\n";
            cout << "Input pair again\n";
            rejected_count++;
            continue;
        }
        if(!(isNum(input_value))){
            cout << "Value should not contain words\n";
            cout << "Input pair again\n";
            rejected_count++;;
            continue;
        }
        week_days_input.push_back(input_day);
        values.push_back(stoi(input_value));
    }
    for(int i = 0;i<values.size();i++)sum+=values[i];
    cout << "Total value: " << sum << endl;
    cout << "Rejected count: " << rejected_count << endl;

}
