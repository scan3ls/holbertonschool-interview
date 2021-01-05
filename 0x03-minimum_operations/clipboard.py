class Clipboard:
    """
        Handles Copy and Paste actions
        and counts number of actions
        executed
    """

    def __init__(self, data):
        """
        --------------
        Method: __init__
        --------------
        Description:
            constructor
        Args:
            None
        --------------
        """
        self.__h = 1
        self.__clipboard = 0
        self.__operations = 0
        self.__n = data

    def __str__(self):
        """
        --------------
        Method: __str__
        --------------
        Description:
            Return a string representaion of the clipboard.
        Args:
            None
        """
        string = ""
        for i in range(self.__h):
            string += "H"
        return string

    def copy(self):
        """
        --------------
        Method: copy
        --------------
        Description:
            set 'clipboard' to the value of  'h' Increase 'operations' by 1
        Args:
            None
        --------------
        """
        self.__clipboard = self.__h
        self.__operations += 1

    def paste(self):
        """
        --------------
        Method: paste
        --------------
        Description:
            Increase value 'h' by the value store in 'clipboard'
            and increase 'operations' by one
        Args:
            None
        --------------
        """
        self.__h += self.__clipboard
        self.__operations += 1

    def get_operations(self):
        """
        --------------
        Method: get_operations
        --------------
        Description:
            Return the number of operations executed
        Args:
            None
        --------------
        """
        return self.__operations

    def get_nums(self):
        """
        --------------
        Method: get_nums
        --------------
        Description:
            Gets the progression of numbers from 1 to N
            using a copy & paste process
        Example:
            Given N: 9

            1 => Copy & Paste => 2 => Paste =>
            3 => Copy & Paste => 6 => Paste => 9

            Result: [1, 2, 3, 6, 9]
        Args:
            None
        --------------
        """
        array = []
        n = self.__n

        if n <= 1:
            return array

        step = int(n / 2)
        array.append(n)
        while n > 1:

            for factor in range(2, n):
                if n % step == 0 and n / step != 1:
                    break
                step = int(n / factor)

            n -= step
            array.append(n if n > 0 else 1)

        array.sort()
        return array
