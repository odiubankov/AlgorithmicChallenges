#ifndef ALGORITHMICCHALLENGES_6_ANIMALSHELTER_H
#define ALGORITHMICCHALLENGES_6_ANIMALSHELTER_H

#include <list>
#include <limits>
#include <string>

class AnimalShelter {
public:
    class Animal {
    private:
        unsigned int id_ = 0;
        std::string name_;

    public:
        Animal(std::string name) : name_{std::move(name)} {};
        virtual ~Animal() {}
        Animal(const Animal& animal) = default;
        Animal(Animal&& animal) = default;
        Animal& operator=(const Animal& animal) = default;
        Animal& operator=(Animal&& animal) = default;

        const std::string& getName() const { return name_; }

        friend class AnimalShelter;
    };

    class Cat : public Animal { using Animal::Animal; };
    class Dog : public Animal { using Animal::Animal; };

public:
    void enque(Animal&& animal) {
        setId(animal);
        if (auto cat = dynamic_cast<Cat*>(&animal)) {
            cats_.push_back(std::move(*cat));
        } else {
            auto dog = static_cast<Dog*>(&animal);
            dogs_.push_back(std::move(*dog));
        }
    }

    void enque(const Animal& animal) {
        if (auto cat = dynamic_cast<const Cat*>(&animal)) {
            auto catCopy = *cat;
            setId(catCopy);
            cats_.push_back(std::move(catCopy));
        } else {
            auto dog = static_cast<const Dog*>(&animal);
            auto dogCopy = *dog;
            setId(dogCopy);
            dogs_.push_back(std::move(dogCopy));
        }
    }

    Dog&& dequeueDog() {
        Dog&& dog = std::move(*begin(dogs_));
        dogs_.pop_front();
        return std::move(dog);
    }

    Cat&& dequeueCat() {
        Cat&& cat = std::move(*begin(cats_));
        cats_.pop_front();
        return std::move(cat);
    }

    Animal&& dequeueAny() {
        if (cats_.empty() || (!dogs_.empty() && cats_.front().id_ > dogs_.front().id_))
            return dequeueDog();

        return dequeueCat();
    }

    void setInitialCounter(unsigned int counter) {
        counter_ = counter;
        cats_.clear();
        dogs_.clear();
    }

private:
    void setId(Animal& animal) {
        if (cats_.size() + dogs_.size() == std::numeric_limits<unsigned int>::max())
            throw;

        if (counter_ == std::numeric_limits<unsigned int>::max()) {
            unsigned int newCounter = 0;
            auto catIt = begin(cats_);
            auto dogIt = begin(dogs_);
            while (catIt != end(cats_) || dogIt != end(dogs_)) {
                if (catIt == end(cats_)) {
                    dogIt->id_ = newCounter++;
                    ++dogIt;
                    continue;
                }
                if (dogIt == end(dogs_)) {
                    catIt->id_ = newCounter++;
                    ++catIt;
                    continue;
                }
                if (catIt->id_ < dogIt->id_) {
                    catIt->id_ = newCounter++;
                    ++catIt;
                } else {
                    dogIt->id_ = newCounter++;
                    ++dogIt;
                }
            }

            counter_ = newCounter;
        }

        animal.id_ = counter_++;
    }

    std::list<Cat> cats_;
    std::list<Dog> dogs_;
    unsigned int counter_ = 0;
};

#endif //ALGORITHMICCHALLENGES_6_ANIMALSHELTER_H
