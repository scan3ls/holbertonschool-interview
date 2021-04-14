#!/usr/bin/python3

rain = __import__('0-rain').rain
tests = {
    0: {
        'walls': [0, 1, 0, 2, 0, 3, 0, 4],
        'answer': 6
    },
    1: {
        'walls': [4, 3, 2, 1, 1, 2, 3, 4],
        'answer': 12
    },
    2: {
        'walls': [1, 2, 3, 4, 4, 3, 2, 1],
        'answer': 0
    },
    3: {
        'walls': [4, 0, 3, 1, 5, 0, 2, 3],
        'answer': 12
    },
    4: {
        'walls': [],
        'answer': 0
    }
}

if __name__ == "__main__":

    for test in tests:
        walls = tests[test].get('walls')
        answer = tests[test].get('answer')

        print(f"\nTest {test} w/ {walls}\n")
        response = rain(walls)

        print(f"\nGot {response}\nExpected {answer}\n")
        print('+++++++++++++++++++\n')
