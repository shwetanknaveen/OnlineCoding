//Problem link - https://leetcode.com/problems/design-a-food-rating-system/

class FoodRatings {
public:
    map<string,map<int,set<string>>> cuisRatFoods;
    map<string,string> foodCuis;
    map<string,int> foodRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            (cuisRatFoods[cuisines[i]])[ratings[i]].insert(foods[i]);//in cuisines[i], with ratings[i], insert this foods[i]
            foodCuis[foods[i]] = cuisines[i];//foods[i] belongs to cuisines[i]
            foodRating[foods[i]] = ratings[i];//foods[i] has rating = ratings[i]
        }
    }
    
    void changeRating(string food, int newRating) {
        int prevRat = foodRating[food];
        foodRating[food] = newRating;
        //cuisine of this food will be foodCuis[food] hence remove this food from map of the previous rating
        //from its cuisine
        (cuisRatFoods[foodCuis[food]])[prevRat].erase(food);
        
        //If after this deletion, there is no more food in the prevRat in that cuisine then remove the map
        //of that rating from that cuisine
        if((cuisRatFoods[foodCuis[food]])[prevRat].size()==0)
        {
            (cuisRatFoods[foodCuis[food]]).erase(prevRat);
        }
        //insert this food in the new rating map in the corresponding cuisine
        (cuisRatFoods[foodCuis[food]])[newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *(((cuisRatFoods[cuisine].rbegin())->second).begin());
        //Go to the cuisine and pick the map's last entry which will have highest rating foods in that cuisine and pick the first of that set which will be lexicographically smallest
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
