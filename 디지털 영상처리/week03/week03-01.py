import numpy as np

# =============================================================================
# def prn_cnt():
#     global counter
#     count = 200
# 
# count = 100
# prn_cnt()
# 
# =============================================================================

def prn_cnt():
    count = 300
    # count = 200
    print(count)

count = 100
global counter
count = 200
prn_cnt()

# =============================================================================
# scores1 = [10, 20, 30]
# scores2 = [70, 80, 90]
# total = scores1 + scores2
# print(total)
# 
# scores1 = np.array([10, 20, 30])
# scores2 = np.array([70, 80, 90])
# total = scores1 + scores2
# print(total)
# =============================================================================

# =============================================================================
# print(total.shape), print(total.ndim), print(total.dtype)
# print(scores1[2]), print(scores1[1:3])
# =============================================================================

# =============================================================================
# ages = np.array([18, 19, 25, 20])
# y = ages > 20
# print(y)
# 
# y = ages[ages>20]
# print(y)
# =============================================================================

# =============================================================================
# y = [ [1,2,3], [4,5,6], [7,8,9]]
# np_array = np.array(y)
# np_array[0,0] = 12
# print(np_array)
# np_array[2,2] = 1.234 
# print(np_array)
# x = np_array[0:2, 1:3]
# print(x)
# =============================================================================

# =============================================================================
# print(np.arange(1,6))
# print(np.arange(1,10,2))
# 
# print(np.array(range(5)))
# 
# print(np.linspace(0, 10, 10))
# print(np.logspace(0, 5, 10))
# =============================================================================

# =============================================================================
# x = np.arange(12)
# print(x)
# y = x.reshape(3,4)
# print(y)
# 
# z = y.flatten()
# print(z)
# =============================================================================

# =============================================================================
# np.random.seed(100)
# print(np.random.rand(5))
# 
# x = np.arange(12)
# y = np.arange(12)
# print(np.mean(x)), print(np.median(x))
# print(np.corrcoef(x, y))
# =============================================================================

