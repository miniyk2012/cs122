# cs122
网易云课堂: https://mooc.study.163.com/learn/1000103000#/learn/announce

实验楼: https://www.lanqiao.cn/courses/122/learning/?id=386 微信或手机验证码登陆


## lab1
```
# 编译
gcc -o hello hello.c
# 执行
./hello
# 打包, 一般不包含可执行文件, 先rm hello
tar -zcvf yk_lab1.tar.gz ./*
# 解包
tar -xzvf yk_lab1.tar.gz 
```

## lab2
1. 编写menu.c脚本
    1. 实现了8个命令: quit triangle rectangle randomnumber newline randomchar line sleep
    2. help: 可以查看8个命令
    3. triangle: 画三角形
    4. rectangle: 画矩形
    5. randomnumber: 输出随机数字
    6. newline: 输出空行
    7. randomchar: 输出随机字符
    8. line: 画一条线
    9. sleep: 睡眠效果
2. gcc menu.c -o menu
3. ./menu
 
