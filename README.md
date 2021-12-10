# 6883Project

eod historicaldata token: 61ad392951f604.64641793

## 12/10/2021 update
- DataReader is ready. Retrieve all price data in 2 min (N=70)
- changed the data structure price data to imrpove efficieny. price dates and price value are stored in two vectors. added startingdate & endgingdate variable
- updated related member functions in class Stock. added a default constructor and a copy constructor