import sys
import numpy as np
import matplotlib.pyplot as plt
import plotly.express as px



def main(argv):

    with open(argv[1]) as f:
        vect = f.readlines()

    fig = px.histogram(vect)
    fig.show()
    return




if __name__ == "__main__":
    main(sys.argv)
