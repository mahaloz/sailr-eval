# JIL:
# JOERN Intermediate Language
#

from copy import deepcopy

class Statement:
    def __init__(self, raw_text, source_line_number=None, **kwargs):
        self.raw_text = raw_text
        self.source_line_number = source_line_number

    @classmethod
    def op_seperator(cls, sub_type):
        return None

    def __str__(self):
        return self.raw_text

    def __repr__(self):
        return f"<{self.__class__.__name__}: {self.__str__()}>"

    def copy(self):
        # TODO make this better in the future!
        return deepcopy(self)


class Assignment(Statement):
    def __init__(self, raw_text, src, dst, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.src = src
        self.dst = dst

    @classmethod
    def op_seperator(cls, sub_type):
        return "="

    def __str__(self):
        return f"{self.src} = {self.dst}"


class Return(Statement):
    def __init__(self, raw_text, ret, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.ret = ret

    @classmethod
    def op_seperator(cls, sub_type):
        return "return"

    def __str__(self):
        return f"return {self.ret}"


class Call(Statement):
    def __init__(self, raw_text, func, args, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.func = func
        self.args = args

    @classmethod
    def op_seperator(cls, sub_type):
        return "return"

    def __str__(self):
        return f"{self.func}({''.join(self.args)})"


class Compare(Statement):
    EQ = 0
    GTE = 1
    GT = 2
    LTE = 3
    LT = 4
    NE = 5

    def __init__(self, raw_text, type_, arg1, arg2, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.type = type_
        self.arg1 = arg1
        self.arg2 = arg2

    def _pretty_seperator(self):
        op_map = {
            self.EQ: "==",
            self.GTE: ">=",
            self.GT: ">",
            self.LT: "<",
            self.LTE: "<=",
            self.NE: "!=",
        }

        return op_map[self.type]

    @classmethod
    def op_seperator(cls, sub_type):
        op_map = {
            cls.EQ: "==",
            cls.GTE: "&gt;=",
            cls.GT: "&gt;",
            cls.LT: "&lt;",
            cls.LTE: "&lt;=",
            cls.NE: "!="
        }

        return op_map.get(sub_type, None)

    def __str__(self):
        return f"{self.arg1} {self._pretty_seperator()} {self.arg2}"


class Ternary(Statement):
    def __init__(self, raw_text, cond, true, false, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.cond = cond
        self.true = true
        self.false = false

    @classmethod
    def op_seperator(cls, sub_type):
        return ""

    def __str__(self):
        return f"{self.cond} ? {self.true} : {self.false}"


class UnaryOp(Statement):
    pass


class BinOp(Statement):
    SUB = 0
    ADD = 1
    AND = 2
    OR = 3

    def __init__(self, raw_text, type_, arg1, arg2, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.type = type_
        self.arg1 = arg1
        self.arg2 = arg2

    def _pretty_seperator(self):
        op_map = {
            self.SUB: "-",
            self.ADD: "+",
            self.AND: "&&",
            self.OR: "||",
        }

        return op_map[self.type]

    @classmethod
    def op_seperator(cls, sub_type):
        op_map = {
            cls.SUB: "minus",
            cls.ADD: "plus",
            cls.AND: "logicalAnd",
            cls.OR: "logicalOr",
        }

        return op_map.get(sub_type, None)

    def __str__(self):
        return f"{self.arg1} {self._pretty_seperator()} {self.arg2}"


class Nop(Statement):
    FUNC_START = 0
    FUNC_END = 1
    NOP = 2

    str_map = {
        FUNC_START: "FUNCTION_START",
        FUNC_END: "FUNCTION_END",
        NOP: "NOP"
    }

    def __init__(self, raw_text, type_, **kwargs):
        super().__init__(raw_text, **kwargs)
        self.type = type_

    def __str__(self):
        return f"{self.str_map.get(self.type, None)}"


class UnknownStmt(Statement):
    def __str__(self):
        return f"<{self.__class__.__name__}: {self.raw_text}>"

    def __repr__(self):
        return self.__str__()


class UnsupportedStmt(Statement):
    def __str__(self):
        return f"<{self.__class__.__name__}: {self.raw_text}>"

    def __repr__(self):
        return self.__str__()


class MergedRegionStart(Statement):
    def __init__(self, source_line_number=None, total_nodes=0, **kwargs):
        super().__init__("", source_line_number=source_line_number)
        self.total_nodes = total_nodes

    def __str__(self):
        return f"<{self.__class__.__name__}: {self.source_line_number}, {self.total_nodes} Nodes>"
