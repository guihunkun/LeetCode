class Solution {
public:
    int totalMoney(int n) {
        // 所有完整的周存的钱
        int weekNumber = n / 7;
        int firstWeekMoney = (1 + 7) * 7 / 2;
        int lastWeekMoney = firstWeekMoney + 7 * (weekNumber - 1);
        int weekMoney = (firstWeekMoney + lastWeekMoney) * weekNumber / 2;
        // 剩下的不能构成一个完整的周的天数里存的钱
        int dayNumber = n % 7;
        int firstDayMoney = 1 + weekNumber;
        int lastDayMoney = firstDayMoney + dayNumber - 1;
        int dayMoney = (firstDayMoney + lastDayMoney) * dayNumber / 2;
        return weekMoney + dayMoney;
    }
};

