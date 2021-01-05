class Clipboard:
    """
        Handles Copy and Paste actions
        and counts number of actions
        executed
    """

    def __init__(self):
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

    def __str__(self):
        """
        --------------
        Method: __str__
        --------------
        Description:
            Return a string representaion
            of the clipboard.
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
            set 'clipboard' to
            the value of  'h'
            Increase 'operations'
            by 1
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
            Increase value 'h' by
            the value store in
            'clipboard' and
            increase 'operations'
            by one
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
            Return the number of
            operations executed
        Args:
            None
        --------------
        """
        return self.__operations
