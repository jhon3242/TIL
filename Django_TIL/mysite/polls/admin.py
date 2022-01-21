from django.contrib import admin
from .models import Choice, Question, Choice

admin.site.register(Question)
admin.site.register(Choice)
