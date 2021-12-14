from numpy import NaN
import yfinance as yf
import ta

class fn:

	def __init__(self, asset):
		self.asset = {'현금' : asset}  # 시작 자산
		pass

	def buy(self, price, count, day):
		""" 주식을 매수하는 함수 """
		if (self.asset < price * count):
			print("돈이 충분하지 않습니다.")
			return


		pass

	def sell(self, price, count, day):
		""" 주식을 매도하는 함수 """
		pass

	@staticmethod
	def diff(a, b):
		if a > b:
			return a - b
		else:
			return b - a


def op():
		""" 자동 매매 함수 """

		ticker = 'FNGU'
		start_day = '2021-04-01'
		data = yf.download(ticker,start = '2021-01-01') 	# 시작날을 입력 받으면 그 이후 33일 정도 기록누락 발생
		if start_day not in data.index:
			print('해당 날은 주가 기록이 없습니다.')
			return
		data = data.reset_index()						# 날짜 인덱스를 열로 바꾸고 숫자 인덱스 사용
		rsi = ta.momentum.rsi(data['Close'])
		mfi = ta.volume.money_flow_index(data['High'],data['Low'],data['Close'],data['Volume'])
		macd = ta.trend.macd(data['Close'])
		macd_sig = ta.trend.macd_signal(data['Close'])

		p_data = data['Close']
		for i in range(len(p_data)):
			if rsi[i] <= 35 and mfi[i] <= 35  and fn.diff(macd[i], macd_sig[i]) >= 0.1:
				print(i)







op()
