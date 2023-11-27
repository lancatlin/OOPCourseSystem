# Homework 05

> 這份作業主要由國立臺北科技大學 109 資工系黃漢軒所命題，若有任何的問題，非常歡迎使用以下的聯絡方式提問：
> Email: t109590031@ntut.org.tw／MS Teams: 黃漢軒／Telegram: @xuan910625

⚠️ Due: 11:59 p.m., 04 / 12 / 2023 ⚠️



## 作業目標

這份作業主要希望你能夠熟悉以下的事項，以利於跟進未來課程的發展：

 - [x] 學習多型相關技巧。
 - [x] 瞭解如何使用多型解決相關問題。



## 檔案架構

**請清掉前一次的作業**，確認提交是否符合以下的檔案架構，否則無法進行評分。

```
.
├── CMakeLists.txt
├── LICENSE
├── README.md
├── files.cmake
├── include
│   ├── Car.hpp
│   ├── ElectricCar.hpp
│   ├── ElectricMotorcycle.hpp
│   ├── ElectricVehicle.hpp
│   ├── Motorcycle.hpp
│   ├── ParkingSystem.hpp
│   └── Vehicle.hpp
├── scripts
│   ├── CodeCoverage.cmake
│   └── coverage.sh
├── src
│   ├── Car.cpp
│   ├── ElectricCar.cpp
│   ├── ElectricMotorcycle.cpp
│   ├── ElectricVehicle.cpp
│   ├── Motorcycle.cpp
│   ├── ParkingSystem.cpp
│   └── Vehicle.cpp
└── test
    ├── ut_Car.cpp
    ├── ut_ElectricCar.cpp
    ├── ut_ElectricMotorcycle.cpp
    ├── ut_Motorcycle.cpp
    └── ut_ParkingSystem.cpp
```



## 題目敘述

> 在這個任務中，你將嘗試描述停車場管理系統（Parking Area）



曾經有一個有趣的梗圖說過，停車場的計費方式可以是每小時支付輪子數量乘以 5 的金額。

![用車輪數計費！停車場超吸睛網：考算數能力嗎| EBC 東森新聞| LINE TODAY](https://obs.line-scdn.net/0hiDq9GPFNNmtMQB3Uu5NJPHYWNQR_LCVoKHZnaA8uaF80JXhqIC98BW8XbFgzInE1InR9D2FCLVoycHU-cCB8/w644)

在這個停車場中，我們支援「電動車」、「汽車」、「電動摩托車」與「摩托車」的停車格，這些車子具有不同的計費方式：

- 對於「電動車」、「汽車」來說，需要每小時酌收 40 元。
- 對於「電動摩托車」、「摩托車」來說，需要每小時酌收 25 元。
- 如果車輛本身是含有電的，停車場給予充電服務並酌收電費。
  - 計算方式：（電池總容量 - 電池當前剩餘電量）* 5。

你必須要提供該載具取得停車費的函式，並且也提供新增載具、移除載具與計算載具數量的函式。



我們希望這個停車管理系統具有一個「特定車種車牌查詢系統」：

- 可以透過 template 來傳入載具類別。
- 回傳所有特定種類載具的車牌 `vector`。

你必須要能夠提供一個函數來查詢某載具類別的所有車牌。



我們希望這個停車管理系統具有一個「當前一小時收益評估系統」：

- 計算每小時這個停車場可以獲得多少收益。
- 需要同時記入車輛電費。



## 任務敘述

> 我們已經提前幫你完成了 `Car.hpp`、`ElectricCar.hpp`、`ElectricMotorcycle.hpp` 以及 `Motorcycle.hpp`。
>
> 另外這些車種有他們的上層類別 `ElectricVehicle.hpp` 以及 `Vehicle.cpp`。
>
> 在做功課時請務必確認這些類別的實作細節。



在這份功課，你必須將 `ParkingSystem.hpp` 實作完成。

- 成員 `std::vector<std::shared_ptr<Vehicle>> vehicles;`
  - 用於儲存停車場的車輛，車輛為一個 `std::shared_ptr` 的物件。
- `void AddVehicle(std::shared_ptr<Vehicle> vehicle)`
  - 新增車輛，傳入一個 `std::shared_ptr` 的車輛物件。
  - 如果停車場已經有相同車牌的車輛了，那麼你應該拋出例外 `std::invalid_argument` 來防止相同車牌的車輛被加入停車場。
- `void RemoveVehicle(std::string plateNumber)`
  - 移除車輛，傳入車牌，並將具有該車牌的車輛移除。
  - 如果停車場沒有該車牌的車輛，你應該拋出例外 `std::invalid_argument` 來防止不存在的車輛被刪除。
- `int GetTotalParkingPricePerHour()`
  - 取得當前一小時的收益，收益必須包含電動車的充電電費。
  - 你可以加總每輛車停一小時的金額。
- `int CalculateParkingPrice(std::string plateNumber, int hour)`
  - 取得某台車輛停放 `hour` 小時後的繳費金額。
  - 如果停車場沒有該車牌的車輛，你應該拋出例外 `std::invalid_argument` 來防止不存在的車輛被刪除。
  - 對於一台電動車的電費，我們收取（電池總容量 - 電池當前剩餘電量）* 5 的電費，僅收取一次（不是每小時收取）。
  - 例如有一台電動汽車停放 3 小時，其電費為 45 元，則這台汽車需要繳費 165 元。
- `template <typename T> std::vector<std::string> Select()`
  - 取得所有特定類別的車輛車牌，並將其彙整成 `std::vector` 後回傳。

詳情見 `ParkingSystem.hpp`，我們有提供一些 Function Signature 在 private 區塊中，實作完成後可能會幫助你實作更加順利。



## 任務備註

- 如果你要從 `Vehicle` 向下轉型成子類別，可以用這一個方式：

  ```c++
  std::shared_ptr<ElectricVehicle> electricVehicle = std::dynamic_pointer_cast<ElectricVehicle>(vehicle);
  ```

- 對於 `std::invalid_argument`，你可以參考 https://en.cppreference.com/w/cpp/error/invalid_argument



## 作業配分

- ［60%］通過 TA 的測試。
  - 依照測試通過的比例配分。
    - Car 相關的測試案例：10%。
    - ElectricCar 相關的測試案例：10%。
    - ElectricMotorcycle 相關的測試案例：10%。
    - Motorcycle 相關的測試案例：10%。
    - ParkingSystem 相關的測試案例：60%。
  - 取得綠色勾勾，每個測試皆通過。
  - 沒有 Memory Leak 的問題。
- ［40%］完成測試覆蓋率任務。
  - 確保測試覆蓋率（Line Coverage）達到 95%。



## 注意事項

- 若你想要有空指標，請將指標賦值（assign） `nullptr` ，這個特殊的指標可用於指向不存在的東西。
- 對於 Google Test 的測試函數：
  - 使用 `ASSERT_EQ` 來測試不會有精度誤差的值（例如：整數、字串等）
  - 使用 `ASSERT_NEAR` 來測試具有精度的值
  - 使用 `ASSERT_THROW` 來測試該函數會不會拋出例外
  - 使用 `ASSERT_FALSE` 來測試該值是否為 `false`
- 你不應該上傳 `/bin` 資料夾至專案上。
  - 你的功課不應該出現 Memory Leak，否則將會扣除作業總分 $10$ 分。
  - 你不應該上傳 `/bin` 資料夾至專案庫，編譯結果不應該上傳至專案庫上，若在助教確認功課評分時 `/bin` 資料夾存在在專案庫中，扣除作業總分 $5$ 分。
- 你可以使用 `debugger` 工具來進行除錯，有利於尋找漏洞與理解漏洞為何會發生。


## Meme

![](https://i.imgflip.com/86x2zr.jpg)