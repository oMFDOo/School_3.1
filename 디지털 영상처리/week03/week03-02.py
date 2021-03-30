import cv2
import numpy as np

# =============================================================================
# img_gray = cv2.imread('./images/mandrill.jpg', cv2.IMREAD_GRAYSCALE)
# img_color = cv2.imread('./images/mandrill.jpg', cv2.IMREAD_COLOR)
# 
# cv2.imshow('grayscale', img_gray)    # 회색조 이미지로 화면에 표시
# cv2.imshow('color image', img_color) # 컬러 이미지로 화면에 표시
# 
# # 다음 두 행은 키보드 입력을 기다렸다가 모든 창을 끄고 종료하는 코드
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# cv2.waitKey(1)  # 화면 Holding 되어 있을 때
# =============================================================================

# =============================================================================
# img = cv2.imread('./images/mandrill.jpg', cv2.IMREAD_COLOR)
# cv2.line(img, (0,0), (200,200), (0,0,255), 5) # 직선 시작/끝점, 색상, 두께
# cv2.rectangle(img, (0,200), (200,20), (0,0,0), 5)  # 사각형의 
# cv2.putText(img, "hello", (70,70), fontFace = 2,               fontScale = 1, color = (0,0,0)) # 텍스트
# cv2.imshow('lined', img)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# cv2.waitKey(1)
# 
# =============================================================================


# =============================================================================
# img1 = cv2.imread('./images/messi.jpg')
# img2 = cv2.imread('./images/ronaldo.jpg')
# 
# addimg = cv2.addWeighted(img1, 0.5, img2, 0.5, 0)
# cv2.imshow('Add', addimg)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# cv2.waitKey(1)
# =============================================================================


# =============================================================================
# image = cv2.imread('./images/mandrill.jpg')
# image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
# 
# blue_low = np.array([80, 0, 0])
# blue_high = np.array([130, 255, 255])
# 
# my_mask = cv2.inRange(image_hsv, blue_low, blue_high) 
# 
# cv2.imshow('original', image)
# cv2.imshow('mask', my_mask)
# 
# extracted = cv2.bitwise_and(image, image, mask=my_mask)
# cv2.imshow('extracted', extracted)
# 
# # 다음 두 행은 키보드 입력을 기다렸다가 모든 창을 끄고 종료하는 코드
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# cv2.waitKey(1)
# =============================================================================


# =============================================================================
# org = cv2.imread('./images/mandrill_spnoise_0.1.jpg')
# kernel = np.ones((3, 3), np.float32) / 9
# averaged33 = cv2.filter2D(org, -1, kernel)
# #averaged33 = cv2.medianBlur(org, 5)
# 
# cv2.imshow('original', org)
# cv2.imshow('filtered', averaged33)
# 
# cv2.waitKey(0)
# cv2.destroyAllWindows()
# cv2.waitKey(1)
# =============================================================================












