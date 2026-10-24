class Solution {
    struct Days {
        Days(const std::string& str) 
        {
            static constexpr std::array days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            const int month = 10 * (str[0] - '0') + (str[1] - '0');
            const int day = 10 * (str[3] - '0') + (str[4] - '0');
            for (int i = 0; i < month; i++) value += days_in_month[i];
            value += day;
        }

        int value = 0;
    };

public:
    int countDaysTogether(Days arriveAlice, Days leaveAlice, Days arriveBob, Days leaveBob) const
    {
        const auto arrive = std::max(arriveAlice.value, arriveBob.value);
        const auto leave = std::min(leaveAlice.value, leaveBob.value);
        return arrive <= leave ? leave - arrive + 1 : 0;
    }
};
