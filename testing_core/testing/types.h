//MIT License
//
//Copyright (c) 2017 Mindaugas Vinkelis
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.


#ifndef CPP_SERIALIZERS_BENCHMARK_TESTING_CORE_TYPES_H
#define CPP_SERIALIZERS_BENCHMARK_TESTING_CORE_TYPES_H

#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <valarray>

namespace MyTypes {
    enum Color : uint8_t {
        Red,
        Green,
        Blue
    };

    struct Vec3 {
        float x;
        float y;
        float z;

        bool operator==(const MyTypes::Vec3 &rhs) const {
//            return x == rhs.x &&
//                   y == rhs.y &&
//                   z == rhs.z;
//    //compare with epsilon 0.05f
    std::valarray<float> lh({x, y, z});
    std::valarray<float> rh({rhs.x, rhs.y, rhs.z});
    return (std::abs(lh - rh) < 0.05f).min();
        };
    };

    struct Weapon {
        std::string name;
        int16_t damage;

        bool operator==(const Weapon &rhs) const {
            return name == rhs.name &&
                   damage == rhs.damage;
        };
    };

    typedef uint64_t chrono_time;
    typedef uint32_t chrono_index;
    typedef uint64_t StoryId;
    typedef uint64_t ClientId;
    typedef std::tuple <chrono_time, ClientId, chrono_index> EventSequence;

    struct LogEvent {
      StoryId storyId;
      uint64_t eventTime;
      ClientId clientId;
      uint32_t eventIndex;
      std::string logRecord;

      bool operator==(const LogEvent &other) const
      {
        return (storyId == other.storyId && eventTime == other.eventTime && clientId == other.clientId &&
            eventIndex == other.eventIndex && logRecord == other.logRecord);
      }

      LogEvent& operator=(const LogEvent& other)
      {
        if (this != &other) // protect against invalid self-assignment
        {
          // copy data members
          this->storyId = other.storyId;
          this->eventTime = other.eventTime;
          this->clientId = other.clientId;
          this->eventIndex = other.eventIndex;
          this->logRecord = other.logRecord;
        }
        // by convention, always return *this
        return *this;
      }
    };

    struct Monster {
        //Vec3 pos;
        //int16_t mana;
        //int16_t hp;
        //std::string name;
        //std::vector<uint8_t> inventory;
        //Color color;
        //std::vector<Weapon> weapons;
        //Weapon equipped;
        //std::vector<Vec3> path;
        StoryId storyId;
        uint64_t startTime;
        uint64_t endTime;
        uint64_t revisionTime;
        std::map <EventSequence, LogEvent> logEvents;

        bool operator==(const MyTypes::Monster &rhs) const {
            //eeturn pos == rhs.pos &&
            //       mana == rhs.mana &&
            //       hp == rhs.hp &&
            //       name == rhs.name &&
            //       inventory == rhs.inventory &&
            //       color == rhs.color &&
            //       weapons == rhs.weapons &&
            //       equipped == rhs.equipped &&
            //       path == rhs.path;
            return storyId == rhs.storyId &&
                   startTime == rhs.startTime &&
                   endTime == rhs.endTime &&
                   revisionTime == rhs.revisionTime &&
                   logEvents == rhs.logEvents;
        };

        Monster& operator=(const Monster& other)
        {
          if (this != &other) // protect against invalid self-assignment
          {
            // copy data members
            this->storyId = other.storyId;
            this->startTime = other.startTime;
            this->endTime = other.endTime;
            this->revisionTime = other.revisionTime;
            this->logEvents = other.logEvents;
          }
          // by convention, always return *this
          return *this;
        }
    };

    std::vector<Monster> createMonsters(size_t count);
}

#endif //CPP_SERIALIZERS_BENCHMARK_TESTING_CORE_TYPES_H
