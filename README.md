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






