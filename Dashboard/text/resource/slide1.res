(Layout slide1
    (Components
		(SubLayout                      Layout1)
    )
	
	(Resources
		(.Label                         "����ǶԻ������")
		(.Layout
			(Grid (Rows 1) (Cols 1 0 0 0 0)
				Layout1	
			)
		)
	)
)

(Layout Layout1
	(Components
		(PushButton                     msg_btn)
	)
	(Resources
		(.Resizeable           True)
		(msg_btn.Label          "����slide1�Ĳ��԰�ť")
		(.Layout
			(Grid (Rows 1) (Cols  1)
				msg_btn
			)
		)
    )
)
