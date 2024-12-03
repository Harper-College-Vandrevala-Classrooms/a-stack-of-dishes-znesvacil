#include <iostream>

using namespace std;

class Dish {
  private:
    string description;

  public:
    Dish() : description("") {} //Added this as an empty Dish object
    
    Dish(string description) {
      this->description = description;
    }

    string get_description() {
      return this->description;
    }
};

class DishStack {
private:
    static const int MaxSize = 10; //Small size for purposes of testing
    Dish DishArray[MaxSize];
    Dish *DishPointer = DishArray;
    int DishSize = 0;
    
public:
    DishStack() : DishSize(0) {}
    
    int size()
    {
        return DishSize;
    }
    
    void push(Dish dish)
    {
        if (DishSize < MaxSize) {
            *DishPointer = dish; // Sets the pointed value of the array to the pushed Dish object
            DishPointer++; // Moves the pointer one to the right
            DishSize++;
        }
        else {
            cout << "You cannot stack any more dishes!" << endl;
        }
    }
    
    Dish pop()
    {
        if (DishSize > 0) {
            DishPointer--; // Moves the pointer one to the left
            DishSize--;
            return *DishPointer;
        }
        else {
            cout << "There are no dishes in the stack." << endl;
            return Dish();
        }
    }
    
    Dish peek()
    {
        return *(DishPointer - 1); // Since the pointer is pointing to the one after the last one pushed, it must be offset by one
    }
    
};

int main() {
    DishStack stack;
    Dish one_dish = Dish("A dish with one fish pattern on it");
    Dish two_dish = Dish("A dish with two fish patterns on it");
    Dish red_dish = Dish("A dish with a red fish pattern on it");
    Dish blue_dish = Dish("A dish with a blue fish pattern on it");

    // The variable stack_size should equal zero.
    int stack_size = stack.size();
    cout << "The variable stack_size = " << stack_size << endl;

    stack.pop(); // This shouldn't pop anything, and should give an error message
    
    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(red_dish);
    stack.push(blue_dish);

    // The variable size_after_pushes should equal four.
    int size_after_pushes = stack.size();
    
    cout << "The variable size_after_pushes = " << size_after_pushes << endl;
    
    // The variable peeked_dish should have a description of "A dish with a blue fish pattern on it"
    Dish peeked_dish = stack.peek();
    cout << "The variable peeked_dish has the description: " << peeked_dish.get_description() << endl;
    
    // The variable popped_dish should have a description of "A dish with a blue fish pattern on it"
    Dish popped_dish = stack.pop();
    cout << "The variable popped_dish has the description: " << popped_dish.get_description() << endl;

    // The variable another_popped_dish should have a description of "A dish with a red fish pattern on it"
    Dish another_popped_dish = stack.pop();
    cout << "The variable another_popped_dish has the description: " << another_popped_dish.get_description() << endl;

    // The variable final_size should equal two.
    int final_size = stack.size();
    cout << "The variable final_size = " << final_size << endl;
    
    stack.push(blue_dish); // 3
    stack.push(blue_dish); // 4
    stack.push(blue_dish); // 5
    stack.push(blue_dish); // 6
    stack.push(blue_dish); // 7
    stack.push(blue_dish); // 8
    stack.push(blue_dish); // 9
    stack.push(blue_dish); // 10, at its max!!
    stack.push(blue_dish); // 11, this last one should give an error
    
    return 0;
}

