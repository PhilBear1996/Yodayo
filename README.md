#題目 : 俄羅斯方塊

#題目說明 : 
	隨機一個方塊將從上方緩緩落下，
	當區域中某一橫行（列）的格子全部由方塊填滿時，
	則該列會被消除並成為玩家的得分。
    
#組別 : 第四組

#GtHub網址 : 
	https://github.com/PhilBear1996/Yodayo.git

#組員名單 : 
    鐘敏榮 B0247796
    劉君猷 B0222815 
    余長安 B0247737
    
#UML圖 
    ![image](https://user-images.githubusercontent.com/101238831/163676192-fea0ba31-97b2-4915-8274-593e6493bd3b.png)

#分工
	鐘敏榮
	{tetris.h，歡迎介面、設定顏色、Main函式
	}
	劉君猷 
	{函式庫、變數、draw函數、介面設定
	}
	余長安
	{方塊設定(圖形、旋轉、消除)、印出分數
	}
		

更新 ：
	4／５ 建Tetris.h 檔
  	4／１４ 新增Tetris.cpp 檔(需要的函式庫與變數)
	4／１４ 新增方塊設定
	4／１６ 新增draw函式
	4／１６ 補充方塊設定
	4／１７ 新增歡迎介面
	4 / 1 9 加了T型	
	4 / 2 1 新增顏色設定
	4 / 2 2 setColor除錯、修正welcome
	5／3 新增reDraw函式與drawMap函式
	5／１１ 新增judge函式與updata函式
	5／１４ 新增pause函式與input_score函式
	5 /1 5 新增運行遊戲的run函式
	5 /1 5 補充完畢run函式
	5 /1 6 修改setColor的case變數數量與run的變數(id、next_id)
	5 /1 6 run符號除錯、更動welcome排版方式、編輯main函式
	5 /1 7 修改welcome的變數
	5 /1 8 修改run的switch與rank變數
	5 /1 9 檢查程式並除錯
#組員名單 : 
鐘敏榮(組長)、劉君猷(組員)、余長安(組員)
