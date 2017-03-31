<font size=4 face="微软雅黑">

http://blog.csdn.net/igolang/article/details/8620626
---
<br>
S.lower() #小写 

S.upper() #大写 

S.swapcase() #大小写互换 

S.capitalize() #首字母大写

---

S.ljust(width,[fillchar]) #输出width个字符，S左对齐，不足部分用fillchar填充，默认的为空格。 

S.rjust(width,[fillchar]) #右对齐 

S.center(width, [fillchar]) #中间对齐 

S.zfill(width) #把S变成width长，并在右对齐，不足部分用0补足

---

S.find(substr, [start, [end]]) #返回S中出现substr的第一个字母的标号，如果S中没有substr则返回-1。start和end作用就相当于在S[start:end]中搜索 

S.index(substr, [start, [end]]) #与find()相同，只是在S中没有substr时，会返回一个运行时错误 

S.rfind(substr, [start, [end]]) #返回S中最后出现的substr的第一个字母的标号，如果S中没有substr则返回-1，也就是说从右边算起的第一次出现的substr的首字母标号 

S.rindex(substr, [start, [end]]) 

S.count(substr, [start, [end]]) #计算substr在S中出现的次数 

S.replace(oldstr, newstr, [count]) #把S中的oldstar替换为newstr，count为替换次数。这是替换的通用形式，还有一些函数进行特殊字符的替换 

S.strip([chars]) #把S中前后chars中有的字符全部去掉，可以理解为把S前后chars替换为None 

S.lstrip([chars]) 

S.rstrip([chars]) 

S.expandtabs([tabsize]) #把S中的tab字符替换没空格，每个tab替换为tabsize个空格，默认是8个

---

S.split([sep, [maxsplit]]) #以sep为分隔符，把S分成一个list。maxsplit表示分割的次数。默认的分割符为空白字符 

S.rsplit([sep, [maxsplit]]) 

S.splitlines([keepends]) #把S按照行分割符分为一个list，keepends是一个bool值，如果为真每行后而会保留行分割符。 

S.join(seq) #把seq代表的序列──字符串序列，用S连接起来 

---


 