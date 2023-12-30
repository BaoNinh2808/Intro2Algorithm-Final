# Introduction to Algorithm Thinking - Final Term

## Bài 1:

## Bài 2:

Gọi $g(n)$ là số lượng các cặp p,q khác nhau sao cho $p+q=2×n$ và $p,q$ là nguyên tố. Hai cặp được gọi là khác nhau nếu 1 trong 2 số tham gia vào cặp này và không tham gia vào cặp còn lại. Cho số nguyên $n$. Hãy tính giá trị biểu thức: $f(n)=g(2)+g(3)+…+g(n)$.

**Dữ liệu vào**:  
Chứa số nguyên $n$ với $3≤n≤10^3$.

**Kết quả**:  
Gồm một số nguyên duy nhất là giá trị $f(n)$.

**Ví dụ**:

|INPUT   | OUTPUT   |
|:------:|:-------: |
|9       | 12       |


## Bài 3
Cho hai dãy số nguyên $A = (a_1, a_2, \dots, a_m)$ và $B = (b_1, b_2, \dots, b_n)$. Tìm một phần tử $a_i$ trong dãy $A$ và một phần tử $b_j$ trong dãy $B$ có $|a_i + b_j|$ là nhỏ nhất có thể.

**Dữ liệu vào**:
- Dòng 1 chứa hai số nguyên dương $m, n \leq 10^5$.
- Dòng 2 chứa $m$ số nguyên $a_1, a_2, \dots, a_m$ (∀${i}: |a_i| < 2 \times 10^9$).
- Dòng 3 chứa $n$ số nguyên $b_1, b_2, \dots, b_n$ (∀${i}: |b_i| < 2 \times 10^9$).

**Kết quả**: Ghi ra 2 chỉ số $i$ và $j$ của hai phần tử tương ứng tìm được.

**Ví dụ**:
- INPUT:
```
4 5
1 8 2 9
-5 -6 3 -7 -4
```
- OUTPUT
```
2 4
```

**[Solution](./Bài%203/3.md)**

## Bài 4

Cho số $n$ và một dãy gồm n số $a_1,a_2,…a_n$. Định nghĩa cặp số nghịch nhau là cặp hai số $a_i$ và $a_j$ trong dãy thỏa điều kiện $i < j$ và $a_i > a_j$. 

**Yêu cầu**: Đếm số lượng các cặp số nghịch nhau trong dãy.  

**Dữ liệu vào**:
- Dòng đầu tiên chứa một số nguyên $n$ với $1 ≤ n ≤5×10^4$.  
- Dòng thứ 2 chứa $n$ số nguyên $a_1,a_2,…a_n$ ($-2^{31} ≤ a_i ≤ 2^{31}$).

**Kết quả**:  
- Gồm một số nguyên duy nhất là số lượng các cặp số nghịch nhau trong dãy.

**Ví dụ**:
INPUT       | OUTPUT
:----:      |:-----:
6           | 5
1 2 4 3 5 1 |    


## Bài 5:

## Bài 6:

Cho k dãy gồm các số nguyên đã được sắp xếp sẵn theo thứ tự tăng dần trong mỗi danh sách. Các phần tử trong dãy có thể có cùng giá trị.

**Yêu cầu**: Hãy gộp tất cả k dãy này lại thành một danh sách đã được sắp xếp theo thứ tự tăng dần.

**Dữ liệu vào**
- Dòng đầu tiên chứa số nguyên k là số lượng các dãy số. $(1≤k≤10^4)$
- k dòng tiếp theo, mỗi dòng chứa một dãy các số nguyên được sắp xếp theo thứ tự tăng dần. Mỗi dòng chứa không quá 500 số nguyên.
- Tổng số lượng các phần tử trong k dãy không vượt quá $10^4$.

**Kết quả**
- Gồm một dòng chứa dãy số đã được gộp lại theo thứ tự tăng dần.

**Ví dụ:**

INPUT | OUTPUT
:----:|:-----:
3   | 1 1 2 3 4 4 5 6
1 4 5 |
1 3 4 |
2 6 |


## Bài 7
Cho một dãy gồm $n$ số nguyên không âm là giá trị độ cao của một vùng đất. Một cơn mưa đủ nhiều đổ lên vùng đất này và nước còn đọng lại như hình bên dưới. Biết rằng nước có thể chảy về các vị trí thấp hơn kề cạnh nếu mực nước ở vị trí hiện tại lớn hơn vị trí kề cạnh. Hai biên của vùng đất là biển và có mực nước bằng 0.

**Yêu cầu**: Hãy tính tổng lượng nước còn đọng lại sau cơn mưa.

**Dữ liệu vào**:
- Dòng đầu tiên chứa số nguyên dương $n$ là chiều rộng của vùng đất ($0 \leq n \leq 3 \times 10^4$).
- Dòng thứ hai chứa $n$ số nguyên không âm $h_i$ là độ cao tại vị trí $i$ trên vùng đất đó. ($0 \leq a_i \leq 10^5$).

**Kết quả**: Gồm một số nguyên duy nhất là tổng lượng nước tại tất cả các vị trí sau cơn mưa.

**Ví dụ**:
- INPUT:
```
6
4 2 0 3 2 5
```
- OUTPUT:
```
9
```

**[Solution](./Bài%207/7.md)**

## Bài 8

Cho bàn cờ kích thước n×n. Hãy tìm tất cả các cách đặt n quân hậu lên bàn cờ này sao cho không có 2 quân hậu nào có thể tấn công lẫn nhau. Biết rằng các quân hậu có thể di chuyển theo hàng dọc, hàng ngang và đường chéo. Bên dưới là 2 ví dụ cách đặt 4 quân hậu lên bàn cờ 4×4.

**Dữ liệu vào**  

- Gồm số n là kích thước cạnh của bàn cờ và số lượng quân hậu. (1≤n≤9)

**Kết quả**

- Dòng đầu tiên chứa số m là số cách đặt các quân hậu khác nhau có thể có.
- Các dòng bên dưới chứa các ma trận đại diện cho bàn cờ kết quả. 
    + Các ma trận cách nhau bởi một dòng trống.
    + Mỗi ma trận gồm n dòng. Mỗi dòng chứa n ký tự:
        - Ký tự ‘.’ biểu diễn tại vị trí ô trống 
        - Ký tự ‘Q’ biểu diễn vị trí đó chứa quân hậu
**Ví dụ:**

INPUT |OUTPUT
:----:|:----:
4     |2   
    |.Q..
    |...Q
    |Q...
    |..Q.
    |
    |..Q.
    |Q...
    |...Q
    |.Q..


## Bài 9
Cho 2 chuỗi $s$ và $p$ gồm các ký tự latin in thường `a`-`z`. Trong chuỗi $p$ có thể có thêm các ký tự `*` và `.` với ý nghĩa:
Ký tự `*` biểu diễn rằng có thể lặp lại ký tự ngay trước đó một hoặc nhiều lần hoặc có thể không lặp lại lần nào. Ví dụ: chuỗi `abbbb` có thể được sinh ra từ chuỗi `ab*` hoặc chuỗi `a` cũng có thể được sinh ra từ chuỗi `ab*`.
Ký tự `.` biểu diễn rằng chỉ có thể thay thế cho một ký tự duy nhất tại vị trí đó trong chuỗi. Ví dụ: chuỗi `abc` có thể được sinh ra từ chuỗi `a.c` hoặc `ab.`. 

**Yêu cầu**: Kiểm tra xem chuỗi $s$ có phải được sinh ra từ chuỗi $p$ hay không.

**Dữ liệu vào**:
- Dòng đầu tiên chứa chuỗi $s$ ($len(s) \leq 20$).
- Dòng thứ hai chứa chuỗi $p$ ($len(p) \leq 30$).

**Kết quả**: Trả về `true` nếu chuỗi $s$ có thể được sinh ra từ chuỗi $p$, và `false` nếu ngược lại.

**Ví dụ**:
- INPUT:
```
mississippi
mis*is*p*.
```
- OUTPUT:
```
false
```

**[Solution](./Bài%209/9.md)**


## Bài 10

Cho một ma trận kích thước m×n chứa các số 0 hoặc 1 tại mỗi ô. 

**Yêu cầu:** Tìm hình vuông lớn nhất chứa toàn số 0 hoặc toàn số 1.

**Ví dụ hình ảnh:**

| 1 | 0 | 1 | 0 | 0 |
|---|---|---|---|---|
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |

**Dữ liệu vào**

- Dòng đầu tiên chứa 2 số nguyên dương m và n tương ứng là số lượng dòng và cột của ma trận. (1≤m,n≤100).

- m dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 cách nhau bởi khoảng trắng.

**Kết quả**

- Diện tích của hình vuông lớn nhất chứa toàn số 1 hoặc toàn số 1

**Ví dụ:**

|INPUT | OUTPUT|
|:---:|:----:|
4 5 | 2
1 0 1 0 0 |
1 0 1 1 1 |
1 1 1 1 1 |
1 0 0 1 0 |

## Bài 11

## Bài 12

Hãy chỉ ra cách xây dựng một hình vuông có diện tích là số nguyên dương S cho trước với các tọa độ nguyên trong phạm vi từ $-10^9$ đến $10^9$.

**Input:** Số nguyên dương S≤$10^3$.

**Output:** Tọa độ 4 đỉnh của hình vuông được liệt kê cùng hoặc ngược chiều kim đồng hồ. Trường hợp không có lời giải thì thông báo Impossible.

|INPUT  | OUTPUT |
|:-----:|:------:|
|5      | 1 2
|       | 2 4
|       | 4 3
|       | 3 1
|3      | Impossible

## Bài 13
Trong mặt phẳng cho $n (n \leq 10^3)$ điểm có tọa độ nguyên sao cho không có 2 điểm nào trùng nhau và không có 3 điểm nào thẳng hàng ($n$ là một số chẵn). 

**Yêu cầu**: Hãy chọn ra 2 điểm trong số n điểm để đường thẳng qua 2 điểm này chia tập điểm thành 2 phần có số lượng điểm bằng nhau.

**Dữ liệu vào**:
- Dòng đầu tiên: $n (2 \leq n \leq 10^3)$.
- Dòng thứ $i$ trong $n$ dòng tiếp theo: $x_i, y_i (|x_i|, |y_i| \leq 10^6)$ - toạ độ của điểm thứ $i$.

**Kết quả**: Gồm 2 số là số thứ tự của 2 điểm được chọn.

**Ví dụ**:
- INPUT:
```
6
3 5
1 3
3 1
6 1
8 3
6 5
```
- OUTPUT:
```
2 5
```

**[Solution](./Bài%2013/13.md)**

## Bài 15