print("돈이 얼마있어요?")
money = int(input())
print("카드가 있나요? 1 or 0")
card = int(input())
if money >= 3800 or card:
    print("택시 ㄱ")
else:
    print("걸어 ㄱ")