# C++实现的简易同名文件夹病毒筛查
本项目还在同时托管在[gitee](https://gitee.com/Geniucker/easy-scanner-of-the-same-name-folder-virus)、[GitHub](https://github.com/Geniucker/easy-scanner-of-the-same-name-folder-virus)、[GitLab](https://gitlab.com/Geniucker/easy-scanner-of-the-same-name-folder-virus)
#### 介绍
学校的教学机中流行着同名文件夹病毒，我用C++实现了一个简单的筛查器（通过观察病毒复制不会改变文件大小，且这个大小不存在于系统文件，因此用文件大小和后缀名判断是否为病毒），**本程序主要可用于学校教学机，在家有杀毒软件也没必要用这玩意儿**



#### 使用方法
1. 从release页面下载对应系统版本的程序压缩包（~~32位和64位不能混用~~v0.0.3及之后的版本32位和64位使用同一的版本，学校班级教室的教学机一般是32位的）并解压到某一目录（建议解压到桌面上的某一个文件夹，防止因为权限的问题造成错误）。链接：  
[从gitee下载](https://gitee.com/Geniucker/easy-scanner-of-the-same-name-folder-virus/releases)（中国大陆推荐使用这个，但是要登录）  
[从GitLab下载](https://gitlab.com/Geniucker/easy-scanner-of-the-same-name-folder-virus/-/releases)（也推荐这个且不用登陆）  
[从GitHub下载](https://github.com/Geniucker/easy-scanner-of-the-same-name-folder-virus/releases)
2. 打开`scan.exe`程序
3. 根据提示输入或拖入要扫描的文件夹或盘符
4. 若发现疑似病毒的文件运行结束后会在程序的目录下生成`result+数字.txt`文件（下面简称`配置文件`），内容为疑似程序的全路径，多次执行`scan.exe`程序产生的`result+数字.txt`的`数字`将依次增大
5. 打开生产的`配置文件`文件，手动确认是否为病毒（可通过观察图标是否为Windows XP的文件夹样式判断），把确认不是病毒的路径从`配置文件`文件删除（整行都要删掉），保存并关闭`配置文件`文件
6. 打开`clean.exe`程序，根据提示选择刚才经过编辑确认的`配置文件`文件的序号
7. 程序将删除`配置文件`中指向的文件，若成功删除数远少于总数请确认`配置文件`选择是否正确
8. 重复上述操作确认是否都已删除

#### 说明
1. 写程序的时候没怎么做异常处理，请尽量按说明使用避免造成错误
2. 如果在运行`scan.exe`还没输入要扫描的文件夹但不小心按下回车导致程序没反应可直接叉掉重新打开
3. 在Windows 10的系统上首次使用时Windows Defender可能会提示扫描，但不会报毒（没来就是用来杀毒的当然不会有毒啦），不影响使用（当然从目前的试验来看这种病毒对Windows 10无效）
4. 如果病毒文件在系统盘若`clean.exe`程序无法删除可尝试以管理员权限再次运行`clean.exe`（这种情况不用再次运行`scan.exe`）（在学校的教学机上使用不会出现这种情况）
5. 由于此病毒有变种导致有不同的大小，不保证能找到所有的病毒
6. 由于未仔细阅读本文档造成数据丢失作者不承担任何责任

#### v0.0.4更新说明
1. 修复删除文件名包含`$`、`(`、`)`、`+`、`.`、`[`、`]`、`^`、`{`、`}`的文件时会引发异常的BUG
#### v0.0.3更新说明
1. 增加了检测病毒是否在进程中的功能，加快了删除文件的速度
#### v0.0.2更新说明
1. 修复了一个v0.0.1严重的BUG（导致输出的疑似病毒文件的路径有误），因此v0.0.1的`main.exe`导出的`配置文件`无效，无法给后续版本的`clean.exe`使用
2. 增加删除病毒文件功能