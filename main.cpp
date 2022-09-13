#include <iostream>
#include <vector>

namespace zadanie_1
{
    void execute();
};

namespace zadanie_2
{
    struct MinMaxResult
    {
        int max;
        int min;
    };
    MinMaxResult minmax(const std::vector<int>& numbers);
    int sum(const std::vector<int>& numbers);
    float mean(const std::vector<int>& numbers);
};

namespace zadanie_3
{
    struct Point
    {
        float x;
        float y;
        Point(float x_value, float y_value);
    };
    struct Rectangle
    {
        float x;
        float y; 
        float width;
        float height;
        Rectangle(float x_value, float y_value, float w_value, float h_value);
    };
    bool contains(Rectangle rect, Point p);
    bool intersects(Rectangle rect1, Rectangle rect2);
};

namespace zadanie_4
{
    bool is_prime_number(int number);
    void generate_prime_numbers(int n);
};

int main(int argc, char* argv[])
{
    //zadanie_1::execute();
    zadanie_4::generate_prime_numbers(512);
    return 0;
}

namespace zadanie_1
{
    void execute() 
    {
        std::vector<int> numbers;
        unsigned int size;
        
        std::cin >> size;
        for(int i=0; i<size; i++) {
            int num;
            std::cin >> num;
            numbers.push_back(num);
        }
        
        for(auto it=numbers.end()-1; it>=numbers.begin(); --it)
            std::cout << *it << " ";
        std::cout << std::endl;
        zadanie_2::MinMaxResult result = zadanie_2::minmax(numbers);
        std::cout << "Minimalna liczba w zbiorze to: " << result.min << std::endl;
        std::cout << "Maksymalna liczba w zbiorze to: " << result.max << std::endl;
        std::cout << "Suma liczb to: " << zadanie_2::sum(numbers) << std::endl;
        std::cout << "Srednia to: " << zadanie_2::mean(numbers) << std::endl;
    }
};

namespace zadanie_2
{
    MinMaxResult minmax(const std::vector<int>& numbers)
    {
        MinMaxResult result; 
        result.min = INT_MAX;
        result.max = INT_MIN;
        for(const auto& num : numbers) {
            if(result.min > num)
                result.min = num;
            if(result.max < num)
                result.max = num;
        }
        return result;
    }

    int sum(const std::vector<int>& numbers)
    {
        int sum = 0;
        for(const auto& num : numbers)
            sum += num;
        return sum;
    }

    float mean(const std::vector<int>& numbers)
    {
        return (float)sum(numbers) / (float)numbers.size();
    }
};

namespace zadanie_3
{
    Point::Point(float x_value, float y_value) 
    {
        x = x_value; y = y_value;
    }
    Rectangle::Rectangle(float x_value, float y_value, float w_value, float h_value) {
        x = x_value; y = y_value; width = w_value; 
        height = h_value;
    }
    bool contains(Rectangle rect, Point p) 
    {
        bool conditionX = p.x >= rect.x && p.x <= rect.x+rect.width;
        bool conditionY = p.y >= rect.y && p.y <= rect.y+rect.height;
        if(conditionX && conditionY)
            return true;
        else return false;
    }
    bool intersects(Rectangle rect1, Rectangle rect2)
    {
        Point corners_2[4] = 
        {
            {rect2.x, rect2.y},
            {rect2.x, rect2.y + rect2.height},
            {rect2.x + rect2.width, rect2.y},
            {rect2.x + rect2.width, rect2.y + rect2.height}
        };
        for(int i=0; i<4; i++) {
            if(contains(rect1, corners_2[i]))
                return true;
        }
        Point corners_1[4] = 
        {
            {rect1.x, rect1.y},
            {rect1.x, rect1.y + rect1.height},
            {rect1.x + rect1.width, rect1.y},
            {rect1.x + rect1.width, rect1.y + rect1.height}
        };
        for(int i=0; i<4; i++) {
            if(contains(rect2, corners_1[i]))
                return true;
        } 
        return false;
    }
};

namespace zadanie_4
{
    bool is_prime_number(int number)
    {
        for(int i=2; i<number/2; i++) {
            if(number % i == 0)
                return false;
        }
        return true;
    }
    void generate_prime_numbers(int n)
    {
        for(int i=2; i<n; i++) {
            if(is_prime_number(i))
                std::cout << i << " ";
        }
    }
};

