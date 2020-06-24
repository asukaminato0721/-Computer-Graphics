"""
外环是逆时针，内环顺时针

"""
from wolframclient.evaluation import WolframLanguageSession  # MMA
from wolframclient.language import wl, wlexpr, Global  # MMA
session = WolframLanguageSession()
result = session.evaluate(wlexpr('Range[6]'))
print(result)