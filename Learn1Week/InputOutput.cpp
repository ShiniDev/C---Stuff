#include <std_lib_facilities.h>

//Initialization of functions
bool contains(vector<string>,string);
int squared(int);
int translate(string,int);
bool vector_contains(vector<int>,int);
bool vector_contains_string(vector<string>, string);
double get_input(double,string);

class Student{
public:
    string name;
    int score;
    Student(string s_name,int s_score)
        :name(s_name),score(s_score){}
};

void input()
{
    cout << "Enter the name of the person you want to write to\n";
    string name = " ";
    cin >> name;
    cout << "Dear " << name << ",\n";
    cout << "    Kamusta kana? Ako ok lang, sa ngayun araw araw lang akong nag-aaral ng programming.\n";
    cout << "Enter a name of a friend\n";
    string friend_name = " ";
    cin >> friend_name;
    cout << "Nakikita mo paba si " << friend_name << " ? matagal ko na kasi siyang hindi nakikita\n";
    char friend_sex = 0;
    cout << "Enter m if your friend is male and f if your friend is female\n";
    cin >> friend_sex;
    if(friend_sex == 'm')
        cout << "Pwede mo bang sabihan yung lalake na yun na tawagan ako\n";
    if(friend_sex == 'f')
        cout << "Pwede mo bang sabihan yung babae na yun na tawagan ako\n";
    cout << "How old is the recipient?\n";
    int age = -1;
    cin >> age;
    if(age <= 0 || age >= 110)
        cout << "Pinagloloko moko eh hahahaha!\n";
    else cout << "Narinig ko nag birthday ka daw at " << age << " years old kana\n";
    if(age == 17)
        cout << "Next year pwede kanang bumoto\n";
    else if(age < 12)
        cout << "Next year " << age+1 << " years old kana\n";
    else if(age > 70)
        cout << "Sana palagi kang ingatan ng Diyos\n";
    cout << "Yours sincerely,\n";
    cout << endl;
    cout << "Haba\n";
}
void miles_to_kilometer()
{
    cout << "You are in a place where everybody uses kilometer as a measure of distance\n";
    cout << "Enter miles to convert it to kilometers\n";
    double mi = -1.0;
    cin >> mi;
    double km = mi * 1.609;
    cout << "Kilometers: " << km << "\nMiles: " << mi << "\n";
}
void illegal_names()
{
    //int double = 0;
    //int string = 0;
    //double int = 0;
}
void calculations()
{
    cout << "Enter two numbers, I would perform possible calculations\n";
    int val1 = -1;
    int val2 = -2;
    cin >> val1 >> val2;
    cout << "\nval1 == " << val1;
    cout << "\nval2 == " << val2;
    if(val1 < val2){
        cout << "\nSmaller number: " << val1;
        cout << "\nBigger number: " << val2;
    }
    else if(val1 > val2){
        cout << "\nSmaller number: " << val2;
        cout << "\nBigger number: " << val1;
    }
    cout << "\nval1 + val2 == " << val1+val2;
    cout << "\nval1 - val2 == " << val1-val2;
    cout << "\nval1 * val2 == " << val1*val2;
    cout << "\n" << val1 << ":" << val2 << "\n";

}
void calculations_double()
{
    cout << "Enter two numbers, I would perform possible calculations\n";
    double val1 = -1;
    double val2 = -2;
    cin >> val1 >> val2;
    cout << "\nval1 == " << val1;
    cout << "\nval2 == " << val2;
    if(val1 < val2){
        cout << "\nSmaller number: " << val1;
        cout << "\nBigger number: " << val2;
    }
    else if(val1 > val2){
        cout << "\nSmaller number: " << val2;
        cout << "\nBigger number: " << val1;
    }
    cout << "\nval1 + val2 == " << val1+val2;
    cout << "\nval1 - val2 == " << val1-val2;
    cout << "\nval1 * val2 == " << val1*val2;
    cout << "\n" << val1 << ":" << val2 << "\n";

}
void numerical_sequence()
{
    cout << "Enter three numbers:\n";
    int num1 = -1;
    int num2 = -1;
    int num3 = -3;
    cin >> num1 >> num2 >> num3;
    cout << endl;
    if(num1<num2 && num2<num3)
        cout << num1 << ", " << num2 << ", " << num3 << "\n";
    else if(num2<num1 && num1<num3)
        cout << num2 << ", " << num1 << ", " << num3 << "\n";
    else if(num3<num2 && num2<num1)
        cout << num3 << ", " << num2 << ", " << num1 << "\n";
    else if(num3<num1 && num1<num2)
        cout << num3 << ", " << num1 << ", " << num2 << "\n";
    else if(num2<num3 && num3<num1)
        cout << num2 << ", " << num3 << ", " << num1 << "\n";
    else if(num1<num3 && num3<num2)
        cout << num1 << ", " << num3 << ", " << num2 << "\n";
}
void string_sequence()
{
    cout << "Enter three words:\n";
    string num1 = "???";
    string num2 = "???";
    string num3 = "???";
    cin >> num1 >> num2 >> num3;
    cout << endl;
    if(num1<num2 && num2<num3){
        cout << num1 << ", " << num2 << ", " << num3 << "\n";
    }
    else if(num2<num1 && num1<num3){
        cout << num2 << ", " << num1 << ", " << num3 << "\n";
    }
    else if(num3<num2 && num2<num1){
        cout << num3 << ", " << num2 << ", " << num1 << "\n";
    }
    else if(num3<num1 && num1<num2){
        cout << num3 << ", " << num1 << ", " << num2 << "\n";
    }
    else if(num2<num3 && num3<num1){
        cout << num2 << ", " << num3 << ", " << num1 << "\n";
    }
    else if(num1<num3 && num3<num2){
        cout << num1 << ", " << num3 << ", " << num2 << "\n";
    }
}
void input_even()
{
    cout << "Enter a number:\n";
    int num = -1;
    cin >> num;
    if(num % 2 == 0){
        cout << "Number " << num << " is an even number\n";
    } else {
        cout << "Number " << num << " is an odd number\n";
    }
}
void spelled_numbers()
{
    cout << "Enter a number:\n";
    int num = -1;
    int temp;
    if(cin >> temp){
        num = temp;
        if(num < 0 || num > 4){
            cout << "That's a number, that I don't know :O\n";
        }else if(num == 0){
            cout << "zero\n";
        }else if(num == 1){
            cout << "one\n";
        }else if(num == 2){
            cout << "two\n";
        }else if(num == 3){
            cout << "three\n";
        }else if(num == 4){
            cout << "four\n";
        }
    }else{
        cout << "Dang\n";
    }
}
void input_calculator()
{
    cout << "Enter something like this + 5 5\n";
    string operation = "???";
    int num1 = -1;
    int num2 = -1;
    cin >> operation >> num1 >> num2;
    if(operation=="+"||operation=="plus"){
        cout << "Result: " << num1+num2;
    }else if(operation=="-"||operation=="minus"){
        cout << "Result: " << num1-num2;
    }else if(operation=="*"||operation=="mul"){
        cout << "Result: " << num1*num2;
    }else if(operation=="/"||operation=="div"){
        cout << "Result: " << num1/num2;
    }
}
void input_coins()
{
    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int quarters = 0;
    int half_dollars = 0;
    int one_dollar = 0;
    cout << "How many pennies do you have?\n";
    cin >> pennies;
    cout << "How many nickels do you have?\n";
    cin >> nickels;
    cout << "How many dimes do you have?\n";
    cin >> dimes;
    cout << "How many quarters do you have?\n";
    cin >> quarters;
    cout << "How many half dollar coin do you have?\n";
    cin >> half_dollars;
    cout << "How many one dollar coin do you have?\n";
    cin >> one_dollar;
    if(pennies > 1){
        cout << "You have " << pennies << " pennies\n";
    }else {
        cout << "You have " << pennies << " pennie\n";
    }
    if(nickels > 1){
        cout << "You have " << nickels << " nickels\n";
    }else {
        cout << "You have " << nickels << " nickel\n";
    }
    if(dimes > 1){
        cout << "You have " << dimes << " dimes\n";
    }else {
        cout << "You have " << dimes << " dime\n";
    }
    if(quarters > 1){
        cout << "You have " << quarters << " quarters\n";
    }else {
        cout << "You have " << quarters << " quarter\n";
    }
    if(half_dollars > 1){
        cout << "You have " << half_dollars << " half dollars\n";
    }else {
        cout << "You have " << half_dollars << " half dollar\n";
    }
    if(one_dollar > 1){
        cout << "You have " << one_dollar << " one dollars\n";
    }else {
        cout << "You have " << one_dollar << " one dollar\n";
    }
    nickels *= 5;
    dimes *= 10;
    quarters *= 25;
    half_dollars *= 50;
    one_dollar *= 100;
    double sum = (pennies+nickels+dimes+quarters+half_dollars+one_dollar) / 100.0;
    cout << "The total coin value is $" << sum << "\n";
}
void money_convertion()
{
    cout << "Enter a number followed by its currency,(y,e,p), '53 e'\n";
    double value = -1;
    double temp = -1;
    char currency = '?';
    if(cin >> temp && temp > 0){
        value = temp;
        cin >> currency;
        switch(currency)
        {
        case 'y':
            cout << value << " yen is " << value*0.0096 << " in dollars\n";
            break;
        case 'e':
            cout << value << " yen is " << value*0.0096 << " in dollars\n";
            break;
        case 'p':
            cout << value << " pounds is " << value*1.33 << " in dollars\n";
            break;
        default:
            cout << "I don't know this currency\n";
            break;
        }
    }else cout << "Numbers must not be negative or equal to 0\n";
}
void print_characters()
{
    int i = 0;
    char character = 0;
    for(i;i<128;++i){
        character = i;
        cout << character << '\t' << i << '\n';
    }
}
void square_table()
{
    int value = -1;
    for(int i = 0;i<100;++i){
        value = squared(i);
        cout << i << '\t' << value << '\n';
        value = 0;
    }
}
int squared(int value)
{
    int square = 0;
    int times = value;
    for(int i = 0;i<times;++i){
        square += value;
    }
    return square;
}
void minutes_vector()
{
    vector<double> minutes;
    double minute = 0;
    while(cin >> minute){
        minutes.push_back(minute);
    }
    double sum = 0;
    for(int i = 0;i<minutes.size();i++) sum += minutes[i];
    cout << "The mean of minutes is " << sum/minutes.size() << '\n';
    sort(minutes.begin(), minutes.end());
    cout << "The median of minutes is " << minutes[minutes.size()/2] << '\n';
}
void dictionary()
{
    vector<string> words;
    string word = "";
    while(cin >> word){
        words.push_back(word);
    }
    cout << "Total words in dictionary: " << words.size() << '\n';
    sort(words.begin(),words.end());
    for(int i = 0;i<words.size();i++){
        if(words[i]!=words[i+1]){
            if(words[i] == "Fuck"){
                cout << "BLEEP!" << '\n';
            }else {
                cout << words[i] << '\n';
            }
        }
    }
}
bool contains(vector<string> words, string word)
{
    for(int i = 0;i<words.size();i++){
        if(words[i] == word){
            return true;
        }
    }
    return false;
}
void chapter4_drill()
{
    vector<double> numbers;
    vector<double> temp2numbers;
    double number = 0;
    double smallest = 0;
    double largest = 0;
    string unit = "";
    char test = 'a';
    while(cin >> number){
        test = number;
        if(test == '|')break;
        cin >> unit;
        if(unit == "cm"){
            number /= 100;//Converts cm to meter
        }else if(unit == "m"){
        }else if(unit == "in"){
            number *= 2.54;//Converts first to cm
            number /= 100;//Then converts to meter
        }else if(unit == "ft"){
            number *= 12;//Converts first to inches then to cm then to meter
            number *= 2.54;
            number /= 100;
        }else break;
        numbers.push_back(number);
        temp2numbers.push_back(number);
        if(number > largest){
            largest = number;
            cout << "largest so far\n";
        }
        if(smallest == 0){
            smallest = number;
        }else if(number < smallest){
            smallest = number;
            cout << "smallest so far\n";
        }
        if(temp2numbers.size()%2 == 0){
            if(temp2numbers[0]<temp2numbers[1]){
                cout << "The smaller value is " << temp2numbers[0] << '\n';
                cout << "The larger value is " << temp2numbers[1] << '\n';
                if(temp2numbers[1]-temp2numbers[0] < 1.0/10000000){
                    cout << "The numbers are almost equal\n";
                }
            }else if(temp2numbers[1]<temp2numbers[0]){
                cout << "The smaller value is " << temp2numbers[1] << '\n';
                cout << "The larger value is " << temp2numbers[0] << '\n';
                if(temp2numbers[0]-temp2numbers[1] < 1.0/10000000){
                    cout << "The numbers are almost equal\n";
                }
            }else cout << "Both are equal" << '\n';
            temp2numbers.clear();
        }
    }
    cout << "Largest: " << largest << '\n';
    cout << "Smallest: " << smallest << '\n';
    cout << "Total numbers: " << numbers.size() << '\n';

    double sum = 0;
    for(int i = 0;i<numbers.size();i++){
        sum += numbers[i];
    }

    cout << "Sum of all numbers: " << sum << '\n';


    sort(numbers.begin(),numbers.end());
    for(int i = 0;i<numbers.size();i++){
        cout << "[" << i << "]\t" << numbers[i] << '\n';
    }
}
void precise_median()
{
    vector<int> numbers;
    int number = 0;
    while(cin >> number){
        numbers.push_back(number);
    }
    int median_index = 0;
    sort(numbers.begin(),numbers.end());
    if(numbers.size()%2 != 0){
        median_index = numbers[numbers.size()/2];
    }else if(numbers.size()%2 == 0)
        median_index = ((numbers[numbers.size()/2])+(numbers[(numbers.size()/2)-1]))/2;
    for(int i=0;i<numbers.size();i++)cout << "[" << i << "]\t" << numbers[i] << '\n';
    cout << "Median: " << median_index << '\n';
    cout << "Vector Size: " << numbers.size() << '\n';
}
void distance_between_cities()
{
    vector<double> distances;
    double distance = 0.0;
    while(cin >> distance){
        distances.push_back(distance);
    }
    double smallest = distances[0];
    double largest = distances[0];
    double sum = 0;
    double mean = 0;
    sort(distances.begin(),distances.end());
    for(int i = 0;i<distances.size();i++){
        if(smallest>distances[i]){
            smallest = distances[i];
        }
        if(largest<distances[i]){
            largest = distances[i];
        }
        sum += distances[i];
        cout << "[" << i << "]\t" << distances[i] << '\n';
    }
    mean = (distances[(distances.size()/2)]+distances[(distances.size()/2)-1])/2;
    cout << "Greatest Distance: " << largest << '\n';
    cout << "Smallest Distance: " << smallest << '\n';
    cout << "Total Distance: " << sum << '\n';
    cout << "The mean of the distance: " << mean << '\n';

}
void c_guess_my_number()
{
    cout << "Enter a number between 1 and 100\n";
    int num = 0;
    while(cin>>num){
        if(num>0&&num<101){
            break;
        }else{
            cout << "Enter a number between 1 and 100\n";
        }
    }
    int minimum = 0;
    int maximum = 101;
    int guess = (maximum-minimum)/2;
    char user_input = 'a';
    while(true){
        if(guess >= 50){
            cout << "Is your number greater than " << guess << " ?(y/n)\n";
            cin >> user_input;
            if(user_input == 'y'){
                minimum = guess;
                guess = guess+(maximum-minimum)/2;
            }else if(user_input == 'n'){
                maximum = guess;
                guess = guess-(maximum-minimum)/2;
            }else continue;
        }else if(guess <= 50){
            cout << "Is your number less than " << guess << " ?(y/n)\n";
            cin >> user_input;
            if(user_input == 'y'){
                maximum = guess;
                guess = guess-(maximum-minimum)/2;
            }else if(user_input == 'n'){
                minimum = guess;
                guess = guess+(maximum-minimum)/2;
            }else continue;
        }
        if(guess == num){
            cout << "Your number is: " << num << '\n';
            break;
        }
    }
}
void simple_calculator()
{
    while(true){
    cout << "Enter two numbers and an operator, 30 46.6 *\n";
    char coperator = 'a';
    double num1 = -1;
    double num2 = -2;
    cin >> num1 >> num2 >> coperator;
    switch(coperator){
    case '+':
        cout << "The sum is: " << num1+num2 << '\n';
        break;
    case '-':
        cout << "The difference is: " << num1-num2 << '\n';
        break;
    case '*':
        cout << "The product is: " << num1*num2 << '\n';
        break;
    case '/':
        cout << "The quotient is: " << num1/num2 << '\n';
    case '%':
        {
        int a = num1;
        int b = num2;
        cout << "The remainder is: " << a%b << '\n';
        }
    break;
    default:
        cout << "Invalid operator\n";
        break;
    }
    cout << "Input c to continue" << '\n';
    cin >> coperator;
    if(coperator == 'c')continue;
    }
}
void number_to_word()
{
    vector<string> word_numbers;
    word_numbers.push_back("zero");
    word_numbers.push_back("one");
    word_numbers.push_back("two");
    word_numbers.push_back("three");
    word_numbers.push_back("four");
    word_numbers.push_back("five");
    word_numbers.push_back("six");
    word_numbers.push_back("seven");
    word_numbers.push_back("eight");
    word_numbers.push_back("nine");
    vector<int> numbers;
    for(int i = 0;i<10;i++)numbers.push_back(i);
    while(true){
        cout << "[1]Word input mode\n[2]Number input mode\n[3]Calculator\n[4]Exit\n";
        char user_input = 'a';
        cin >> user_input;
        switch (user_input){
        case '1':
            while(true){
                cout << "Enter word number, zero\n[1]Exit\n";
                string word_number = "zero";
                cin >> word_number;
                if(word_number=="zero"){
                    cout << numbers[0];
                }else if(word_number=="one"){
                    cout << numbers[1];
                }else if(word_number=="two"){
                    cout << numbers[2];
                }else if(word_number=="three"){
                    cout << numbers[3];
                }else if(word_number=="four"){
                    cout << numbers[4];
                }else if(word_number=="five"){
                    cout << numbers[5];
                }else if(word_number=="six"){
                    cout << numbers[6];
                }else if(word_number=="seven"){
                    cout << numbers[7];
                }else if(word_number=="eight"){
                    cout << numbers[8];
                }else if(word_number=="nine"){
                    cout << numbers[9];
                }else if(word_number=="1"){
                    cout << endl;
                    break;
                }else cout << "Invalid input";
                cout << endl;
            }
            break;
        case '2':
            while(true){
            cout << "Enter a number, 0\nEnter -1 to exit\n";
            string number = "??";
            cin >> number;
            if(number=="0"){
                cout << word_numbers[0];
            }else if(number=="1"){
                cout << word_numbers[1];
            }else if(number=="2"){
                cout << word_numbers[2];
            }else if(number=="3"){
                cout << word_numbers[3];
            }else if(number=="4"){
                cout << word_numbers[4];
            }else if(number=="5"){
                cout << word_numbers[5];
            }else if(number=="6"){
                cout << word_numbers[6];
            }else if(number=="7"){
                cout << word_numbers[7];
            }else if(number=="8"){
                cout << word_numbers[8];
            }else if(number=="9"){
                cout << word_numbers[9];
            }else if(number=="-1"){
                cout << endl;
                break;
            }else cout << "Only 0-9";
            cout << endl;
            }
            break;
        case '3':
            while(true){
            cout << "Enter two numbers and an operator, 30 46.6 *\n";
            char coperator = 'a';
            string input1 = "?";
            string input2 = "?";
            int num1 = -2;
            int num2 = -2;
            cin >> input1;
            num1 = translate(input1,num1);
            cin >> input2;
            num2 = translate(input2,num2);
            if(num1==-1||num2==-1)continue;
            cin >> coperator;
            switch(coperator){
            case '+':
                cout << "The sum is: " << num1+num2 << '\n';
                break;
            case '-':
                cout << "The difference is: " << num1-num2 << '\n';
                break;
            case '*':
                cout << "The product is: " << num1*num2 << '\n';
                break;
            case '/':
                cout << "The quotient is: " << num1/num2 << '\n';
            case '%':
                cout << "The remainder is: " << num1%num2 << '\n';
            break;
            default:
                cout << "Invalid operator\n";
                break;
            }
            cout << "Input c to continue" << '\n';
            cin >> coperator;
            if(coperator == 'c')continue;
            break;
            }
            break;
        case '4':
            break;
        default:
            break;
        }
        if(user_input=='4')break;
    }
}
int translate(string input1,int num1)
{
    if(input1=="0"||input1=="zero"){
        num1 = 0;
    }else if(input1=="1"||input1=="one"){
        num1 = 1;
    }else if(input1=="2"||input1=="two"){
        num1 = 2;
    }else if(input1=="3"||input1=="three"){
        num1 = 3;
    }else if(input1=="4"||input1=="four"){
        num1 = 4;
    }else if(input1=="5"||input1=="five"){
        num1 = 5;
    }else if(input1=="6"||input1=="six"){
        num1 = 6;
    }else if(input1=="7"||input1=="seven"){
        num1 = 7;
    }else if(input1=="8"||input1=="eight"){
        num1 = 8;
    }else if(input1=="9"||input1=="nine"){
        num1 = 9;
    }else return -1;
    return num1;
}
void rice_grain()
{
    int64_t grain = 1;
    int64_t total_grains = 0;
    for(int i = 0;i<65;i++){
        if(i!=0){
            grain *= 2;
        }
        total_grains += grain;
        cout << "Square[" << i << "]\t" << grain << " grains of rice\n";
    }
    cout << "Total grain of rice: " << total_grains << '\n';
}
void rock_paper_scissors()
{
    vector<char> moves;
    moves.push_back('r');
    moves.push_back('p');
    moves.push_back('s');
    char computermove = 'a';
    cout << "Enter a random number\n";
    int index = -1;
    cin >> index;
    int random = index;
    if(index%2==0){
        index = 1;
    }else if(index%2!=0){
        index = 2;
    }
    if(random<0){
        --index;
    }else if(random > 1000){
        ++index;
    }else if(random>0){

    }
    if(index>2){
        index = 2;
    }else if(index < 0){
        index = 0;
    }
    cout << "Enter r for rock,p for paper, and s for scissors\n";
    char playermove = 'a';
    cin >> playermove;
    computermove = moves[index];
    switch (playermove){
    case 'r':
        if(computermove=='p'){
            cout << "You lose\n";
        }else if(computermove=='r'){
            cout << "It's a tie\n";
        }else if(computermove=='s'){
            cout << "You win\n";
        }
        break;
    case 'p':
        if(computermove=='p'){
            cout << "It's a tie\n";
        }else if(computermove=='r'){
            cout << "You win\n";
        }else if(computermove=='s'){
            cout << "You lose\n";
        }
        break;
    case 's':
        if(computermove=='p'){
            cout << "You win\n";
        }else if(computermove=='r'){
            cout << "You lose\n";
        }else if(computermove=='s'){
            cout << "It's a tie\n";
        }
        break;
    default:
        cout << "Read the instruction\n";
        break;
    }
}
void prime_numbers()
{
    vector<int> primes;
    int maximum = 1;
    int countpossible = 0;
    int x = 1;
    int y = 1;
    int sum = 0;
    int limit = 100;
    while(true){
        cout << "Find prime numbers up to: \n";
        cin >> limit;
        if(limit>0){
            break;
        }else{
            cout << "Only positive number and greater than 0\n";
        }
    }
    for(int i = 0;i<limit;i++,maximum++){
        countpossible = 0;
        for(x = 1;x<=maximum;x++){
            for(y = 1;y<=maximum;y++){
                if(x * y == maximum){
                    countpossible++;
                    sum = x*y;
                }
            }
        }
        if(countpossible==2){
            primes.push_back(sum);
        }
    }
    cout << "Total Primes: " << primes.size() << '\n';
    for(int i = 0;i<primes.size();i++){
        cout << "[" << i << "]\t" << primes[i] << '\n';
    }
}
void prime_sieve()
{
    vector<int> primes;
    int maximum = 100;
    int i = 0;
    int x = 0;
    while(true){
        cout << "Find how many primes: \n";
        cin >> maximum;
        if(maximum>0){
            break;
        }else cout << "Should be positive and not 0\n";
    }
    for(i=0,x=0;x<maximum;i++){
        if(i==2){
            x++;
            primes.push_back(i);
        }else if(i==3){
            x++;
            primes.push_back(i);
        }else if(i==5){
            x++;
            primes.push_back(i);
        }else if(i==7){
            x++;
            primes.push_back(i);
        }
        if(i%2==0){
        }else if(i%3==0){
        }else if(i%5==0){
        }else if(i%7==0){
        }else if(i==1){
        }else{
            x++;
            primes.push_back(i);
        }
    }
    for(int i = 0;i<primes.size();i++){
        cout << "[" << i << "]\t" << primes[i] << '\n';
    }
}
void find_mode()
{
    vector<int> positive_numbers;
    vector<int> multiple_modes;
    int number = 0;
    int mode = -1;
    int log = 0;
    int previous_final_log=0;
    int previous_final_mode=-1;
    int final_log = 1;
    int final_mode = 0;
    bool multiple_mode = false;
    cout << "Enter a word to stop\n";
    cout << "Enter positive number:\n";
    while(cin>>number){
        if(number<=0){
            cout << "Number not added, only numbers greater than 0\n";
            continue;
        }else{
            cout << "Enter positive number:\n";
        }
        positive_numbers.push_back(number);
    }
    sort(positive_numbers.begin(),positive_numbers.end());
    for(int i = 0;i<positive_numbers.size();i++){
        if(positive_numbers[i] == positive_numbers[i+1] || positive_numbers[i] == positive_numbers[i-1]){
            if(mode==-1){
                mode = positive_numbers[i];
                log = 0;
            }
            if(mode!=positive_numbers[i]){
                previous_final_log = final_log;
                previous_final_mode = final_mode;
                log = 0;
                mode = positive_numbers[i];
                ++log;
            }else{
                ++log;
            }
            if(log>=final_log){
                final_log=log;
                final_mode=mode;
                if(final_log==previous_final_log){
                    multiple_mode = true;
                    if(!(vector_contains(multiple_modes,previous_final_mode))){
                        multiple_modes.push_back(previous_final_mode);
                    }
                }
                if(final_log>previous_final_log){
                    multiple_mode = false;
                }
                if(multiple_mode==false){
                    multiple_modes.clear();
                }
                if(multiple_mode==true){
                    multiple_modes.push_back(final_mode);
                }
            }

        }
    }
    for(int i = 0;i<positive_numbers.size();i++){
        cout << "[" << i << "]\t" << positive_numbers[i] << '\n';
    }
    if(multiple_modes.size()==0){
        cout << "The mode of the array is " << final_mode << '\n';
    }else{
        cout << "There are multiple modes:\n";
        for(int i = 0;i<multiple_modes.size();i++){
            cout << "Mode#" << i+1 << '\t' << multiple_modes[i] << '\n';
        }
    }
}
bool vector_contains(vector<int> primes, int num)
{
    for(int i = 0;i<primes.size();i++){
        if(primes[i]==num){
            return true;
        }
    }
    return false;
}
void mode_string()
{
    vector<string> words;
    vector<string> multiple_modes;
    string word = "???";
    string mode = "???";
    string final_mode = mode;
    string previous_final_mode = final_mode;
    string min_word = "???";
    string max_word = "???";
    int log = 0;
    int final_log = 0;
    int previous_final_log = 0;
    bool multiple_mode = false;
    cout << "Enter a word, enter '-quit' to exit\n";
    while(cin >> word){
        if(word == "-quit"){
            break;
        }
        cout << "Enter a word, enter '-quit' to exit\n";
        words.push_back(word);
    }
    sort(words.begin(),words.end());
    for(int i = 0;i<words.size();i++){
        if(min_word=="???"){
            min_word = words[i];
        }else if(min_word>=words[i]){
            min_word = words[i];
        }
        if(max_word=="???"){
            max_word = words[i];
        }else if(max_word<=words[i]){
            max_word = words[i];
        }
        if(words[i] == words[i+1] || words[i] == words[i-1]){
            if(mode=="???"){
                mode=words[i];
                log = 0;
            }
            if(mode!=words[i]){
                previous_final_log = final_log;
                previous_final_mode = final_mode;
                mode = words[i];
                log = 0;
                ++log;
            }else ++log;
            if(log>=final_log){
                final_log = log;
                final_mode = mode;
                if(final_log==previous_final_log){
                    multiple_mode = true;
                    if(!(vector_contains_string(multiple_modes,previous_final_mode))){
                        multiple_modes.push_back(previous_final_mode);
                    }
                }
                if(final_log>previous_final_log){
                    multiple_mode = false;
                }
                if(multiple_mode == false){
                    multiple_modes.clear();
                }
                if(multiple_mode == true){
                    multiple_modes.push_back(final_mode);
                }
            }
        }

    }
    if(multiple_modes.size()>0){
        cout << "Multiple modes of string detected:\n";
        for(int i = 0;i<multiple_modes.size();i++){
            cout << "[" << i << "]\t" << multiple_modes[i] << '\n';
        }
    }else cout <<"The mode is "<< final_mode << '\n';
    cout << "The max word is " << max_word << '\n';
    cout << "The min word is " << min_word << '\n';

}
bool vector_contains_string(vector<string> words, string word)
{
    for(int i = 0;i<words.size();i++){
        if(words[i]==word){
            return true;
        }
    }
    return false;
}
void quadratic_equation()
{
    cout << "Hi!, I solve quadratic equations!\n";
    double a,b,c,x,x1,x2;
    a = get_input(a,"a");
    b = get_input(b,"b");
    c = get_input(c,"c");
    x = sqrt((b*b)-4*a*c);
    cout << "x is " << x << '\n';
    b = b * -1.0;
    x1 = (b+x)/(2*a);
    x2 = (b-x)/(2*a);
    cout << "Answer: x = " << x1 << " or x = " << x2 << '\n';
}
double get_input(double num,string name)
{
    while(true){
        cout << "Input value for " << name << ":\n";
        cin >> num;
        if(!(cin.fail())){
            return num;
        }else if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input, Please enter a number:\n";
            continue;
        }
    }
}
bool student_exist(vector<Student> students, string name)
{
    for(int i = 0;i<students.size();i++){
        if(students[i].name==name)return true;
    }
    return false;
}
void name_score_pair()
{
    vector<Student> students;
    string name = "???";
    int score = -1;
    bool name_found = false;
    bool score_found = false;
    while(true){
        cin >> name;
        cin >> score;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            break;
        }
        if(!(student_exist(students,name))){
           Student s(name,score);
           students.push_back(s);
        }else if(student_exist(students,name)){
            cout << "Name is already present\n";
        }
    }
    for(int i = 0;i<students.size();i++){
        cout << "(" << students[i].name << "," << students[i].score << ")" << '\n';
    }
    cout << "Find the score of name:\n";
    cin >> name;
    for(int i = 0;i<students.size();i++){
        if(name==students[i].name){
            name_found = true;
            cout << name << " score is " << students[i].score << '\n';
        }
    }
    if(name_found==false){
        cout << "name not found\n";
    }
    cout << "Find the names with the score of:\n";
    cin >> score;
    for(int i = 0;i<students.size();i++){
        if(score==students[i].score){
            cout << students[i].name << '\n';
            score_found = true;
        }
    }
    if(score_found == false){
        cout << "Score not found\n";
    }
}
