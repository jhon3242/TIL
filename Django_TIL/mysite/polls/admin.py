from django.contrib import admin
from .models import Choice, Question

class QuestionAdmin(admin.ModelAdmin):
	fieldset = [
		(None,		{'fields' : ['question_text']}),
		('Date information')
		]


admin.site.register(Question, QuestionAdmin)
# admin.site.register(Choice)
