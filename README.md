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






