from cs50 import get_string

while True:

    # Input Number
    while True:
        cc_num = get_string("Number: ")
        if cc_num.isdigit():
            break

    # Check length
    if len(cc_num) != 13 and len(cc_num) != 15 and len(cc_num) != 16:
        print("INVALID")
        break

    nums = []
    calc = 0

    # Check range
    for i in range(2, len(cc_num) + 1, 2):
        nums.append(int(cc_num[len(cc_num) - i]))

    for num in nums:
        num = num * 2
        if num > 9:
            new = str(num)
            num = int(new[0]) + int(new[1])
        calc = calc + num

    for j in range(1, len(cc_num) + 1, 2):
        calc = calc + int(cc_num[len(cc_num) - j])

    # Print
    if (calc % 10) != 0:
        print("INAVLID")
        break
    if cc_num[0] == '3':
        print("AMEX")
        break
    if cc_num[0] == '4':
        print("VISA")
        break
    if cc_num[0] == '5':
        print("MASTERCARD")
        break