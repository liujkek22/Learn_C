# 1文件的输入输出

## 1.1 文件的读入

```CPP
std::ofstream
char automobile[50];
int year;
double a_price;
double b_price;
// Open file
outfile.open("test.txt"); // Make sure the path is correct
if (!outfile) {
std::cerr << "Error opening file!" << std::endl;
return 1;
}
// User input
std::cout << "Enter the make and model of the automobile: ";
std::cin.getline(automobile, 50);
std::cout << "Enter the model year: ";
std::cin >> year;
std::cout << "Enter the original asking price: ";
std::cin >> a_price;
b_price = 0.918 * a_price;
// Set output format for std::cout
std::cout << std::fixed;
std::cout.precision(2);
std::cout.setf(std::ios_base::showpoint);
// Output to console
std::cout << "Make and model of the automobile: " << automobile << std::endl;
std::cout << "Year: " << year << std::endl;
std::cout << "Original asking price: $" << a_price << std::endl;
std::cout << "Now price: $" << b_price << std::endl;
// Set output format for outfile
outfile << std::fixed;
outfile.precision(2);
outfile.setf(std::ios_base::showpoint);
// Output to file
outfile << "Make and model of the automobile: " << automobile << std::endl;
outfile << "Year: " << year << std::endl;
outfile << "Original asking price: $" << a_price << std::endl;
outfile << "Now price: $" << b_price << std::endl;
// Close file
outfile.close();
```

# 2 判断输入的字符直至'@'结束输出，并将大小写字符相互转换

## 2.1 方法一：直接判断方法

```CPP
std::ifstream
Infile.open(".//test.txt");
if (!Infile.is_open() ){
std::cerr << "Error opening file!" << std::endl;
return 1;
}
char line[100];
Infile.getline(line, 100);
std::cout << line << std::endl;
return 0
char ch;
while ((std::cin.get(ch))) {
if (ch == '@') {
break;
}
if (ch >= 'a' && ch <= 'z') {
ch = ch + ('A' - 'a');
std::cout << ch;
}
else if (ch >= 'A' && ch <= 'Z') {
ch = ch - ('A' - 'a');
std::cout << ch;
}
else if (   static_cast(ch) >= '0' && static_cast(ch) <= '9') {
continue;
}
else {
std::cout << ch;
}
}
```

### 2.2 使用"cctype"库实现

```
int 
char ch;
while (std::cin.get(ch)) {
      if (ch == '@') {
      break;
}
if (std::islower(ch)) {
ch = std::toupper(ch); // 
std::cout << ch;
}
else if (std::isupper(ch)) {
ch = std::tolower(ch); // 
std::cout << ch;
}
else if (std::isdigit(ch)) {
continue; 
}
else {
std::cout << ch; 
}
}
return 0;
}
```

# 计数10次输入，非数字输入则退出并计算平均值和大于平均值个数并输出

```CPP
const int donation = 10;
double test[donation];
double enter_num;
int i = 0;
double sum = 0;
while (i < donation) {
std::cout << "Enter a number: ";
if (!(std::cin >> enter_num)) {
//std::cerr << "Invalid input. Exiting the program." << std::endl;
//return 1;
break;
}
test[i] = enter_num;
sum += enter_num;
++i;
}
int cnt = 0;
double average = sum / i;
for (int j = 0; j < i; ++j) {
if (test[j] < average) {
++cnt;
}
}
std::cout << "The average of the number enter:" << average << std::endl;
std::cout << "The count of numbers below the average: " << cnt << std::endl;
```

# 关于CPP"std::cin>>i"引发的思考

TIPS：
          当 `std::cin >> i` 试图将输入流中的内容读取到 `int` 类型的变量 `i` 中时，它会进行类型匹配和转换。如果读取成功，则输入流 (`std::cin`) 的状态是良好的，`std::cin` 的状态位（如 `std::ios::failbit`、`std::ios::badbit`、`std::ios::eofbit`）不会被设置，此时 `std::cin` 会被转换为 `true`。
          如果输入的内容无法转换为 `int` 类型（例如输入了一个字符 `q`），则会设置 `std::cin` 的 `failbit` 状态位。这会导致 `std::cin` 转换为 `false`。因此，`while (std::cin >> i)` 会在输入无法转换为 `int` 类型时退出循环。

```CPP
#include 
int main() {
int i;
std::cout << "Enter integers (type 'q' to quit):" << std::endl;
while (std::cin >> i) {
std::cout << "You entered: " << i << std::endl;
}
std::cout << "Input terminated." << std::endl;
return 0;
}
```


