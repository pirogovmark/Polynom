#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Btn_Load_clicked()
{
    std::string s = ui->Line_Enter->text().toStdString();
    s = Delete_Scapes(s);
    Check(s);
    if (ui->Line_Error->text() == "CORRECT") {
        ui->Line_Poliz->setText(QString::fromStdString(Invertion(s)));
    }
}

std::string MainWindow::Delete_Scapes(std::string s) {
    std::string ans = "";
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            ans += s[i];
        }
    }
    return ans;
}


bool MainWindow::Check(std::string s) {
    if (s == "") {
        ui->Line_Error->setText(QString::fromStdString("ERROR: line is empty"));
        return 0;
    }
    try {
        for (size_t i = 1; i < s.size(); ++i) {
            if ((s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') &&
                (s[i - 1] == '-' || s[i - 1] == '+' || s[i - 1] == '^' || s[i - 1] == '%' || s[i - 1] == '*' || s[i - 1] == '/')) {
                std::string thrw = "ERROR: two operations in a row";
                throw thrw;
            }
        }
        if (s[0] == '-') {
            std::reverse(s.begin(), s.end());
            s.pop_back();
            std::reverse(s.begin(), s.end());
            return Check(s);
        } else if (s[0] >= '0' && s[0] <= '9') {
            size_t i = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                ++i;
                if (i == s.size()) {
                    break;
                }
            }
            if (i == s.size()) {
                ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                return 1;
            } else {
                if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                    ++i;
                    std::string ans_ = "";
                    for(;i < s.size(); ++i) {
                        ans_ += s[i];
                    }
                    return Check(ans_);
                } else {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
            }
        } else if (s[0] == '(') {
            size_t i = 1;
            int skobki = 1;
            std::string next_1 = "";
            bool done = false;
            for (; i < s.size(); ++i) {
                if (s[i] == '(') {
                    ++skobki;
                } else if (s[i] == ')') {
                    --skobki;
                }
                if (skobki == 0) {
                    done = true;
                    if (!Check(next_1)) {
                        return 0;
                    }
                    break;
                }
                next_1 += s[i];
            }
            if (!done) {
                std::string thrw = "ERROR: incorrect sequence";
                throw thrw;
            } else if (done && Check(next_1)) {
                ++i;
                if (i == s.size()) {
                    ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                    return 1;
                }
                if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                    ++i;
                    std::string ans_ = "";
                    for(;i < s.size(); ++i) {
                        ans_ += s[i];
                    }
                    return Check(ans_);
                } else {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
            }
        } else if (s[0] == '[') {
            size_t i = 1;
            int skobki = 1;
            std::string next_1 = "";
            bool done = false;
            for (; i < s.size(); ++i) {
                if (s[i] == '[') {
                    ++skobki;
                } else if (s[i] == '[') {
                    --skobki;
                }
                if (skobki == 0) {
                    done = true;
                    if (!Check(next_1)) {
                        return 0;
                    }
                    break;
                }
                next_1 += s[i];
            }
            if (!done) {
                std::string thrw = "ERROR: incorrect sequence";
                throw thrw;
            } else if (done && Check(next_1)) {
                ++i;
                if (i == s.size()) {
                    ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                    return 1;
                }
                if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                    ++i;
                    std::string ans_ = "";
                    for(;i < s.size(); ++i) {
                        ans_ += s[i];
                    }
                    return Check(ans_);
                } else {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
            }
        } else if (s.size() >= 6) {
            if (s[0] == 's' && s[1] == 'i' && s[2] == 'n' && s[3] == '(') {
                size_t i = 4;
                int skobki = 1;
                std::string next_1 = "";
                bool done = false;
                for (; i < s.size(); ++i) {
                    if (s[i] == '(') {
                        ++skobki;
                    } else if (s[i] == ')') {
                        --skobki;
                    }
                    if (skobki == 0) {
                        done = true;
                        if (!Check(next_1)) {
                            return 0;
                        }
                        break;
                    }
                    next_1 += s[i];
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                } else if (done && Check(next_1)) {
                    ++i;
                    if (i == s.size()) {
                        ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                        return 1;
                    }
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else if (s[0] == 's' && s[1] == 'i' && s[2] == 'n' && s[3] == '[') {
                size_t i = 4;
                int skobki = 1;
                std::string next_1 = "";
                bool done = false;
                for (; i < s.size(); ++i) {
                    if (s[i] == '[') {
                        ++skobki;
                    } else if (s[i] == ']') {
                        --skobki;
                    }
                    if (skobki == 0) {
                        done = true;
                        if (!Check(next_1)) {
                            return 0;
                        }
                        break;
                    }
                    next_1 += s[i];
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                } else if (done && Check(next_1)) {
                    ++i;
                    if (i == s.size()) {
                        ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                        return 1;
                    }
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else if (s[0] == 'c' && s[1] == 'o' && s[2] == 's' && s[3] == '(') {
                size_t i = 4;
                int skobki = 1;
                std::string next_1 = "";
                bool done = false;
                for (; i < s.size(); ++i) {
                    if (s[i] == '(') {
                        ++skobki;
                    } else if (s[i] == ')') {
                        --skobki;
                    }
                    if (skobki == 0) {
                        done = true;
                        if (!Check(next_1)) {
                            return 0;
                        }
                        break;
                    }
                    next_1 += s[i];
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                } else if (done && Check(next_1)) {
                    ++i;
                    if (i == s.size()) {
                        ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                        return 1;
                    }
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else if (s[0] == 'c' && s[1] == 'o' && s[2] == 's' && s[3] == '[') {
                size_t i = 4;
                int skobki = 1;
                std::string next_1 = "";
                bool done = false;
                for (; i < s.size(); ++i) {
                    if (s[i] == '(') {
                        ++skobki;
                    } else if (s[i] == ')') {
                        --skobki;
                    }
                    if (skobki == 0) {
                        done = true;
                        if (!Check(next_1)) {
                            return 0;
                        }
                        break;
                    }
                    next_1 += s[i];
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                } else if (done && Check(next_1)) {
                    ++i;
                    if (i == s.size()) {
                        ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                        return 1;
                    }
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else if (s[0] == 'l' && s[1] == 'o' && s[2] == 'g' && s[3] == '(') {
                size_t i = 4;
                std::string next_1 = "";
                bool done = false;
                int brackets = 1;
                for(;i < s.size(); ++i) {
                    if (s[i] == ',' && brackets == 1) {
                        if (!Check(next_1)) {
                            return 0;
                        }
                        done = true;
                        break;
                    }
                    if (s[i] == '(') {
                        brackets += 1;
                    }
                    if (s[i] == ')') {
                        brackets -= 1;
                    }
                    next_1 += s[i];
                }
                if (i == s.size()) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
                if (done && Check(next_1)) {
                    ++i;
                    int skobki = 1;
                    std::string next_1 = "";
                    bool done = false;
                    for (; i < s.size(); ++i) {
                        if (s[i] == '(') {
                            ++skobki;
                        } else if (s[i] == ')') {
                            --skobki;
                        }
                        if (skobki == 0) {
                            done = true;
                            if (!Check(next_1)) {
                                return 0;
                            }
                            break;
                        }
                        next_1 += s[i];
                    }
                    if (!done) {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    } else if (done && Check(next_1)) {
                        ++i;
                        if (i == s.size()) {
                            ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                            return 1;
                        }
                        if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                            ++i;
                            std::string ans_ = "";
                            for(;i < s.size(); ++i) {
                                ans_ += s[i];
                            }
                            return Check(ans_);
                        } else {
                            std::string thrw = "ERROR: incorrect sequence";
                            throw thrw;
                        }
                    }
                }
            } else if (s[0] == 'l' && s[1] == 'o' && s[2] == 'g' && s[3] == '[') {
                size_t i = 4;
                std::string next_1 = "";
                bool done = false;
                int brackets = 1;
                for(;i < s.size(); ++i) {
                    if (s[i] == ',' && brackets == 1) {
                        if (!Check(next_1)) {
                            return 0;
                        }
                        done = true;
                        break;
                    }
                    if (s[i] == '[') {
                        brackets += 1;
                    }
                    if (s[i] == ']') {
                        brackets -= 1;
                    }
                    next_1 += s[i];
                }
                if (i == s.size()) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
                if (!done) {
                    std::string thrw = "ERROR: incorrect sequence";
                    throw thrw;
                }
                if (done && Check(next_1)) {
                    ++i;
                    int skobki = 1;
                    std::string next_1 = "";
                    bool done = false;
                    for (; i < s.size(); ++i) {
                        if (s[i] == '[') {
                            ++skobki;
                        } else if (s[i] == ']') {
                            --skobki;
                        }
                        if (skobki == 0) {
                            done = true;
                            if (!Check(next_1)) {
                                return 0;
                            }
                            break;
                        }
                        next_1 += s[i];
                    }
                    if (!done) {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    } else if (done && Check(next_1)) {
                        ++i;
                        if (i == s.size()) {
                            ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                            return 1;
                        }
                        if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                            ++i;
                            std::string ans_ = "";
                            for(;i < s.size(); ++i) {
                                ans_ += s[i];
                            }
                            return Check(ans_);
                        } else {
                            std::string thrw = "ERROR: incorrect sequence";
                            throw thrw;
                        }
                    }
                }
            } else if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
                size_t i = 0;
                while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_') {
                    ++i;
                    if (i == s.size()) {
                        break;
                    }
                }
                if (i == s.size()) {
                    ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                    return 1;
                } else {
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else {
                std::string thrw = "ERROR: incorrect sequence";
                throw thrw;
            }
        } else {
            if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
                size_t i = 0;
                while ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '_') {
                    ++i;
                    if (i == s.size()) {
                        break;
                    }
                }
                if (i == s.size()) {
                    ui->Line_Error->setText(QString::fromStdString("CORRECT"));
                    return 1;
                } else {
                    if (s[i] == '-' || s[i] == '+' || s[i] == '^' || s[i] == '%' || s[i] == '*' || s[i] == '/') {
                        ++i;
                        std::string ans_ = "";
                        for(;i < s.size(); ++i) {
                            ans_ += s[i];
                        }
                        return Check(ans_);
                    } else {
                        std::string thrw = "ERROR: incorrect sequence";
                        throw thrw;
                    }
                }
            } else {
                std::string thrw = "ERROR: incorrect sequence";
                throw thrw;
            }
        }
    } catch (std::string s_) {
        ui->Line_Error->setText(QString::fromStdString("" + s_));
        return 0;
    }
    ui->Line_Error->setText(QString::fromStdString("CORRECT"));
    return 1;
}


std::string MainWindow::Invertion(std::string s) {
    std::stack <std::string> steck;
    std::string ans = "";
    std::string cur_s = "";
    bool done = false;
    char prev;
    bool num = false;
    for (size_t i = 0; i < s.size(); ++i) {
        num = false;
        if (s[i] == ',') {
            cur_s = ",";
            done = true;
        } else if (s[i] == '-' && (i == 0 || prev == '(' || prev == ',')) {
            cur_s = "~";
            done = true;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
            if (s[i] == '-') {
                if (s[i] + 1 == '-') {
                    ;
                } else {
                    if (i == 0) {
                        cur_s += s[i];
                    } else if (s[i - 1] == '(') {
                        cur_s += s[i];
                    } else {
                        cur_s = s[i];
                        done = true;
                    }
                }
            } else {
                cur_s = s[i];
                done = true;
            }
        } else if (s[i] == '(') {
            cur_s = "(";
            done = true;
        } else if (s[i] == ')') {
            cur_s = ")";
            done = true;
        } else if (s[i] == '['){
            cur_s = "[";
            done = true;
        } else if (s[i] == ']') {
            cur_s = "]";
            done = true;
        } else if (i + 3 < s.size()) {
            if (s[i] == 's' && s[i + 1] == 'i' && s[i + 2] == 'n' && s[i + 3] == '(') {
                i += 2;
                cur_s = "sin";
                done = true;
            } else if (s[i] == 'c' && s[i + 1] == 'o' && s[i + 2] == 's' && s[i + 3] == '(') {
                i += 2;
                cur_s = "cos";
                done = true;
            } else if (s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'g' && s[i + 3] == '(') {
                i += 2;
                cur_s = "log";
                done = true;
            } else {
                num = true;
                if (i + 1 < s.size()) {
                    if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' ||
                        s[i + 1] == '%' || s[i + 1] == '^' || s[i + 1] == ',' || s[i + 1] == ')') {
                        cur_s += s[i];
                        done = true;
                    } else {
                        cur_s += s[i];
                    }
                } else if (i == s.size() - 1) {
                    cur_s += s[i];
                    done = true;
                }
            }
        } else if (i + 1 < s.size()) {
            if (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/' ||
                s[i + 1] == '%' || s[i + 1] == '^' || s[i + 1] == ',' || s[i + 1] == ')') {
                cur_s += s[i];
                done = true;
            } else {
                cur_s += s[i];
            }
            num = true;
        } else if (i == s.size() - 1) {
            cur_s += s[i];
            done = true;
            num = true;
        }

        if (s[i] != ' ') {
            prev = s[i];
        }

        if (done) {
            if (num) {
                ans += cur_s;
                ans += " ";
            } else if (cur_s == "sin" || cur_s == "cos" || cur_s == "log" || cur_s == "~") {
                steck.push(cur_s);
            } else if (cur_s == ",") {
                while (steck.top() != "(") {
                    ans += steck.top();
                    ans += " ";
                    steck.pop();
                }
            } else if (cur_s == "-" || cur_s == "+" || cur_s == "^" ||
                       cur_s == "*" || cur_s == "/" || cur_s == "%") {
                if (cur_s == "+") {
                    if (steck.empty() == true) {
                        steck.push("+");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "-" || steck.top() == "+" || steck.top() == "^" ||
                                steck.top() == "*" || steck.top() == "/" || steck.top() == "%" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("+");
                    }
                } else if (cur_s == "-") {
                    if (steck.empty() == true) {
                        steck.push("-");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "-" || steck.top() == "+" || steck.top() == "^" ||
                                steck.top() == "*" || steck.top() == "/" || steck.top() == "%" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("-");
                    }
                } else if (cur_s == "*") {
                    if (steck.empty() == true) {
                        steck.push("*");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "^" || steck.top() == "*" || steck.top() == "/" || steck.top() == "%" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("*");
                    }
                } else if (cur_s == "/") {
                    if (steck.empty() == true) {
                        steck.push("/");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "^" || steck.top() == "*" || steck.top() == "/" || steck.top() == "%" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("/");
                    }
                } else if (cur_s == "%") {
                    if (steck.empty() == true) {
                        steck.push("%");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "^" || steck.top() == "*" || steck.top() == "/" || steck.top() == "%" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("%");
                    }
                } else if (cur_s == "^") {
                    if (steck.empty() == true) {
                        steck.push("^");
                    } else {
                        while (steck.empty() != true) {
                            if (steck.top() == "^" ||
                                steck.top() == "sin" || steck.top() == "cos" || steck.top() == "log" || steck.top() == "~") {
                                ans += steck.top();
                                steck.pop();
                                ans += " ";
                            } else {
                                break;
                            }
                        }
                        steck.push("^");
                    }
                }
            } else if (cur_s == "(") {
                steck.push("(");
            } else if (cur_s == ")") {
                while(steck.top() != "(") {
                    ans += steck.top();
                    ans += " ";
                    steck.pop();
                }
                steck.pop();
                if (steck.empty() == false) {
                    if (steck.top() == "log" || steck.top() == "sin" || steck.top() == "cos" || steck.top() == "~") {
                        ans += steck.top();
                        ans += " ";
                        steck.pop();
                    }
                }
            } else if (cur_s == "[") {
                steck.push("[");
            } else if (cur_s == "]") {
                while(steck.top() != "[") {
                    ans += steck.top();
                    ans += " ";
                    steck.pop();
                }
                steck.pop();
                if (steck.empty() == false) {
                    if (steck.top() == "log" || steck.top() == "sin" || steck.top() == "cos" || steck.top() == "~") {
                        ans += steck.top();
                        ans += " ";
                        steck.pop();
                    }
                }
            }
            cur_s = "";
            done = false;
        }
    }
    while (steck.empty() == false) {
        ans += steck.top();
        ans += " ";
        steck.pop();
    }
    ans.pop_back();
    return ans;
}
