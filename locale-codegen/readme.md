#### 一个小玩具，用于fastio的locale代码生成

函数输入LCID，返回GNU风格的lang字符串

CodeGen输入微软的LCID表，根据GNU风格的lang表找出最佳匹配的pair<lcid,lang>，该表中lcid不重复