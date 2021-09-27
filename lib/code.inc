# -*- mode: org; -*-

#+name: tufte_style_line
#+begin_src python :results none
  import matplotlib.pyplot as plt
  import matplotlib.ticker as ticker
  
  # Global options.
  plt.rcParams['font.family'] = __font
  
  # Plot line, line masks, then dots.
  fig, ax = plt.subplots()
  ax.plot(x, y, linestyle='-', color= __linecolor , linewidth=1, zorder=1)
  ax.scatter(x, y, color='white', s=100, zorder=2)
  ax.scatter(x, y, color='black', s=20, zorder=3)
  
  # Remove axis lines.
  ax.spines['top'].set_visible(False)
  ax.spines['right'].set_visible(False)
  
  # Set spine extent.
  ax.spines['bottom'].set_bounds(min(x), max(x))
  ax.spines['left'].set_bounds(225, 325)
  
  # Reduce tick spacing.
  x_ticks = list(range(min(x), max(x)+1, 2))
  ax.xaxis.set_ticks(x_ticks)
  ax.yaxis.set_major_locator(ticker.MultipleLocator(base=25))
  ax.tick_params(direction='in')
  
  # Adjust lower limits to let data breathe.
  ax.set_xlim([1950, ax.get_xlim()[1]])
  ax.set_ylim([210, ax.get_ylim()[1]])
  
  # Axis labels as a title annotation.
  ax.text(1958, 320, __title)
#+end_src

#+begin_src python :results none var:x
  mystats = open ("stats", r)
  print(x, end="")
#+end_src
#+begin_src python :results file :var __font="serif" :var __linecolor="red" :var __title="testing"
  <<tufte_style_line>>
#+end_src
#+name: trend
#+BEGIN_SRC python :exports none :results file :var name="internet of things"
  import pandas as pd                        
  from pytrends.request import TrendReq
  pytrend = TrendReq()
  df = pytrend.interest_by_region()
  df.reset_index().plot(x='geoName', y = name, figsize=(120, 10), kind ='line')
#+END_SRC
