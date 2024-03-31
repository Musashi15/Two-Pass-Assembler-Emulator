/*
						TITLE : Claims 				 
						
						NAME  	        : Moulik Jain
						ROLL NUMBER     : 2201CS49
						Declaration of Authorship:
						This txt file is part of the assignment of the course CS210 at 
						Department of Computer Science and Engineering, IIT Patna .  
*/

#include <bits/stdc++.h>
using namespace std;
bool isDigit(char c) 
{
    switch (c) 
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}


bool isAlphabet(char c) 
{
    char cc = tolower(c);
    const char alphabets[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; alphabets[i] != '\0'; ++i) 
    {
        if (cc == alphabets[i]) 
        {
            return true;
        }
    }
    return false;
}

bool isValidLabel(string labelName) 
{
    bool isLabelValid = true;
    // Check if the first character is an alphabet
    isLabelValid &= isAlphabet(labelName[0]);
    // Check if the rest of the characters are alphanumeric or underscore
    for (size_t index = 1; index < labelName.length(); ++index) 
    {
        char currentChar = labelName[index];
        isLabelValid &= (isalnum(currentChar) || currentChar == '_');
    }
    return isLabelValid;
}


bool isDecimal(string x) 
{
	bool ok = true;
    int flag = 1;
	for (int i=0;i<x.size();i++)
    {
        char c = x[i];
        if(!isDigit(c))
        {
            flag = 0;
            break;
        }

	}
    if(flag == 1) return true;
    else return false;
	
}

bool isOctal(string octalNumber) 
{
    bool isNumberValid = true;    
    // Check if the string has at least two characters and starts with '0'
    if (octalNumber.size() < 2 || octalNumber[0] != '0') 
    {
        return false;
    } 
    // Check if each character is in the range '0' to '7'
    for (size_t index = 1; index < octalNumber.size(); ++index) 
    {
        if (octalNumber[index] < '0' || octalNumber[index] > '7') {
            return false;
        }
    }
    return true;
}

bool isHexadecimal(string hexadecimalNumber) 
{
    bool isNumberValid = true;
    // Check if the string has at least three characters and starts with '0x' or '0X'
    if (hexadecimalNumber.size() < 3 || (hexadecimalNumber[0] != '0' || (tolower(hexadecimalNumber[1]) != 'x'))) 
    {
        return false;
    }
    // Check if each character after '0x' or '0X' is a valid hexadecimal digit
    for (size_t index = 2; index < hexadecimalNumber.size(); ++index) 
    {
        char currentChar = tolower(hexadecimalNumber[index]);
        if (!isxdigit(currentChar))
        {
            return false;
        }
    }
    return true;
}

string octalToDec(string octalNumber) 
{
    int decimalResult = 0;
    int powerOfEight = 1;
    // Iterate through the string from right to left
    for (int i = octalNumber.size() - 1; i >= 0; --i) 
    {
        // Convert character to integer value
        int digit = octalNumber[i] - '0';
        // Update result by multiplying digit with power of 8
        decimalResult += digit * powerOfEight;
        // Update power of 8 for the next digit
        powerOfEight *= 8;
    }
    // Convert result to string and return
    return to_string(decimalResult);
}


string hexToDec(string hexNumber) 
{
    int decimalResult = 0;
    int powerOfSixteen = 1;
    // Iterate through the string from right to left
    for (int i = hexNumber.size() - 1; i >= 0; --i, powerOfSixteen *= 16) 
    {
        // Calculate the value of the current hexadecimal digit
        int digitValue;
        if (isdigit(hexNumber[i])) {
            digitValue = hexNumber[i] - '0';
        } else {
            digitValue = tolower(hexNumber[i]) - 'a' + 10;
        }
        // Update result by multiplying digit value with power of 16
        decimalResult += powerOfSixteen * digitValue;
    }
    // Convert result to string and return
    return to_string(decimalResult);
}


bool decimal_check(string value) 
{
    if (value.empty()) 
    {
        return false;
    }

    // Check for a leading sign (+ or -)
    size_t start = (value[0] == '+' || value[0] == '-') ? 1 : 0;

    // Check if the remaining characters are all digits
    return start < value.length() && all_of(value.begin() + start, value.end(), ::isdigit);
}
bool octal_check(string value) 
{
    if (value.length() > 1 && value[0] == '0') 
    {
        return all_of(value.begin() + 1, value.end(), [](char c) 
        {
            return (c >= '0' && c <= '7');
        });
    } 
    else 
    {
        return false;
    }
}
bool digits_check(const std::string& temp) 
{
    size_t start_index = 0;

    if (temp.size() >= 2 && temp[0] == '0' && (temp[1] == 'x' || temp[1] == 'X'))  start_index = 2; // Hexadecimal, skip '0x' or '0X'
    else if (temp.size() == 1 && temp[0] == '0') return true; // Special case: "0"
    else if (temp.size() > 1 && temp[0] == '0') start_index = 1; // Octal, skip '0'
    
    for (size_t i = start_index; i < temp.length(); i++) if (!isdigit(temp[i]) && !((temp[i] >= 'a' && temp[i] <= 'f') || (temp[i] >= 'A' && temp[i] <= 'F'))) return false;
    
    return true;
}
bool label_check(string label) 
{
    if (label.length() > 0 && label[label.length() - 1] == ':') 
    {
        char firstChar = label[0];
        return ((firstChar >= 'a' && firstChar <= 'z') || (firstChar >= 'A' && firstChar <= 'Z'));
    }
    return false;
}

bool Operand_check(string operand, unordered_map<string, int> Operand) 
{
    return Operand.count(operand) > 0;
}

bool Operand_type(const string& x) 
{
    unordered_set<string> validOperands{"data", "ldc", "adc", "adj", "SET"};
    return validOperands.count(x) > 0;
}

bool operand_one(string temp) 
{
    unordered_set<string> validInstructions
    {"data", "ldc", "adc", "ldl", "stl", "ldnl", "stnl", "10", "call",
        "brz", "brlz", "br", "SET", "adj"};
    return validInstructions.count(temp) > 0;
}

bool operand_zero(string temp) 
{
    unordered_set<string> validInstructions{"add", "sub", "shl", "shr", "a2sp", "sp2a", "return", "HALT"};
    return validInstructions.count(temp) > 0;
}

vector<int> MachineCodes;	// stores machinie code
int memory[1 << 24];		// stores memory
int A, B, PC, SP, lines = 0;	// registers
pair<int, int> rwPair;

// All operations accoriding to the ISA given				
void ldc(int value) {
	B = A;
	A = value;
}

void adc(int value) {
	A += value;
}

void ldl(int offset) {
	B = A;
	A = memory[SP + offset];
	rwPair = {SP + offset, 0};
}

void stl (int offset) {
	rwPair = {SP + offset, memory[SP + offset]};
	memory[SP + offset] = A;
	A = B;
} 

void ldnl(int offset) {
	A = memory[A + offset];
	rwPair = {SP + offset, 0};
}

void stnl(int offset) {
	rwPair = {SP + offset, memory[SP + offset]};
	memory[A + offset] = B;
}

void add(int value) {
	A += B;
}

void sub(int value) {
	A = B - A;
}

void shl(int value) {
	A = B << A;
}

void shr(int value) {
	A = B >> A;
}

void adj(int value) {
	SP += value;
}

void a2sp(int value) {
	SP = A;
	A = B;
}

void sp2a(int value) {
	B = A;
	A = SP;
}

void call(int offset) {
	B = A;
	A = PC;
	PC += offset;
}

void ret(int value) {
	PC = A;
	A = B;
}
void brz(int offset) {
	if (A == 0) {
		PC += offset;
	}
}

void brlz(int offset) {
	if (A < 0) {
		PC += offset;
	}
}

void br(int offset) {
	PC += offset;
}

void halt(int value) {
	// stop
	return;
}

// some information to call respective function for each operation

vector<string> mnemonics = {"ldc", "adc", "ldl", "stl", "ldnl", "stnl", "add", "sub", 
					"shl", "shr", "adj", "a2sp", "sp2a", "call", "return", "brz", "brlz", "br", "HALT"};

void (*func[])(int value) = {ldc, adc, ldl, stl, ldnl, stnl, add, sub, 
					shl, shr, adj, a2sp, sp2a, call, ret, brz, brlz, br, halt};



map<string, pair<string, int> > operand_table;		// {mnemonic, opcode, type of operand}
string decToHex(int decimalNumber)
{
    unsigned int number = decimalNumber;
    string hexResult = "";
    for (int i = 0; i < 8; ++i, number /= 16) 
    {
        int remainder = number % 16;
        char hexChar;
        if (remainder <= 9) {
            hexChar = char(remainder + '0');
        } else {
            hexChar = char(remainder - 10 + 'A');
        }
        hexResult += hexChar;
    }
    reverse(hexResult.begin(), hexResult.end());
    return hexResult;
}

// is found some error..,
void throwError() {
	cout << "Segmentation Fault(or maybe infinite loop)" << endl;
	cout << "Please check your code" << endl;
	exit(0);
}

// prints the registers
void Trace() {
	printf("PC = %08X, SP = %08X, A = %08X, B = %08X ", PC, SP, A, B);
	// cout << endl;
}

void Read() {
	cout << "Reading memory[" << decToHex(rwPair.first) << "] finds " << decToHex(A) << endl;
}

void Write() {
	cout << "Writing memory[" <<decToHex(rwPair.first) << "] was " << decToHex(rwPair.second) << " now " << decToHex(memory[rwPair.first]) << endl;
}

// Memory before execution
void Before() {
	cout << "memory dump before execution" << endl;
	for (int i = 0; i < (int)MachineCodes.size(); i += 4) {
		cout << decToHex(i) << " ";
		for (int j = i; j < min((int)MachineCodes.size(), i + 4); ++j) {
			cout << decToHex(MachineCodes[j]) << " ";
		}
		cout << endl;
	}
}

// Memory after execution
void After() {
	cout << "memory dump after execution" << endl;
	for (int i = 0; i < (int)MachineCodes.size(); i += 4) {
		cout << decToHex(i) << " ";
		for (int j = i; j < min((int)MachineCodes.size(), i + 4); ++j) {
			cout << decToHex(memory[j]) << " ";
		}
		cout << endl;
	}
}

// considering wipe means resetting A, B, SP, PC
void Wipe() {
	A = B = SP = PC = 0;
}

// Instruction set 
void ISA() {
	cout<<"Opcode Mnemonic Operand"<<'\n';
	cout<<"0      ldc      value "<<"\n";
	cout<<"1      adc      value "<<"\n";
	cout<<"2      ldl      value "<<"\n";
	cout<<"3      stl      value "<<"\n";
	cout<<"4      ldnl     value "<<"\n";
	cout<<"5      stnl     value "<<"\n";
	cout<<"6      add            "<<"\n";
	cout<<"7      sub            "<<"\n";
	cout<<"9      shr            "<<"\n";
	cout<<"10     adj      value "<<"\n";
	cout<<"11     a2sp           "<<"\n";
	cout<<"12     sp2a           "<<"\n";
	cout<<"13     call     offset"<<"\n";
	cout<<"14     return         "<<"\n";
	cout<<"15     brz      offset"<<"\n";
	cout<<"16     brlz     offset"<<"\n";
	cout<<"17     br       offset"<<"\n";
	cout<<"18     HALT           "<<"\n";
	cout<<"       SET      value "<<"\n";
}


// Execute each line after decoding 
int f = 0;
bool executeInstruction(int currentLine, int flag) {
	int opcode = (currentLine & 0xFF);
	int value = (currentLine - opcode);
	value >>= 8;
	++lines;
	(func[opcode])(value);
	int prevPC = PC;
	if ((PC < 0) or (PC > (int)MachineCodes.size()) or (lines > (1 << 24))) {
		throwError();
		return true;
	}
	if (flag == 0) {
		Trace();
		cout << mnemonics[opcode] << " " ;
		if (operand_table[mnemonics[opcode]].second > 0) {
			cout << decToHex(value);
		}
		//cout << PC << " " << prevPC << " ";
		cout << endl;
		if(opcode == 17)
		{
			if(value == -1)
			{
				if(f == 0 )f = 1;
				else 
				{
					cout << "Infinite Loop Detected !! " << endl;
					return true;
				}
			}
		}
	} else if (flag == 1 and (opcode == 2 or opcode == 4)) {
		Read();
	} else if (flag == 2 and (opcode == 3 or opcode == 5)) {
		Write();
	}
	if (opcode >= 18) {
		return true;
	}
	return false;
}

// call for each line
void Run(int flag) {
	while (PC < (int)MachineCodes.size()) {
		int currentLine = MachineCodes[PC++];
		bool toQuit = executeInstruction(currentLine, flag);
		if (toQuit) break;
	}
}

// checking the command choosen
void executeCommand(string command) {
	if (command == "-trace") {
		Run(0);
		cout << "Program execution finished!" << endl;
	} else if (command == "-read") {
		Run(1);
	} else if (command == "-write") {
		Run(2);
	} else if (command == "-before") {
		Run(3);
		Before();
	} else if (command == "-after") {
		Run(3);
		After();
	} else if (command == "-wipe") {
		Wipe();
	} else if (command == "-isa") {
		ISA();
	} else {
		cout << "Invalid command" << endl;
		exit(0);
	}
	cout << lines << " instructions executed" << endl;
}

// reading input from .o file
void takeInput(string filename) {
	ifstream file(filename, ios::in | ios::binary);
	unsigned int cur;
	int counter = 0;
	while(file.read((char*)&cur, sizeof(int))) { 
		MachineCodes.push_back(cur);
		memory[counter++] = cur;
	}
}

// calling required functions
int main(int argc, char* argv[]) {
	if (argc <= 2) {
		cout << "Invalid Format" << endl;
		cout << "Expected format << ./emu [command] filename.o" << endl;
		cout << "Commands are " << endl;
		cout << "-trace  show instruction trace" << endl;
		cout << "-read   show memory reads" << endl;
		cout << "-write  show memory writes" << endl;
		cout << "-before show memory dump before execution" << endl;
		cout << "-after  show memory dump after execution" << endl;
		cout << "-wipe   wipe written flags before execution" << endl;
		cout << "-isa    display ISA" << endl;
		return 0;
	}
	string filename = argv[2];

	
	operand_table["data"] = {"",1};
    operand_table["ldc"]  =  {"00", 1};
    operand_table["adc"]  =  {"01", 1};
    operand_table["ldl"]  = {"02", 2};
    operand_table["stl"]  = {"03", 2};
    operand_table["ldnl"] = {"04", 2};
    operand_table["stnl"] = {"05", 2};
    operand_table["add"]  = {"06", 0};
    operand_table["sub"]  = {"07", 0};
    operand_table["shl"]  =  {"08", 0};
    operand_table["shr"]  =  {"09", 0};
    operand_table["adj"]  =  {"0A", 1};
    operand_table["a2sp"] =  {"0B", 0};
    operand_table["sp2a"] =  {"0C", 0};
    operand_table["call"] =  {"0D", 2};
    operand_table["return"] =  {"0E", 0};
    operand_table["brz"]  =  {"0F", 2};
    operand_table["brlz"] =  {"10", 2};
    operand_table["br"]   =  {"11", 2};
    operand_table["HALT"] =  {"12", 0};
    operand_table["SET"]  =  {"", 1};	

	takeInput(filename);
	string command = argv[1];
	executeCommand(command);
	return 0;
}
