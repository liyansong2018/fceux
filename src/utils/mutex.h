// mutex.h
#pragma once

#ifdef __QT_DRIVER__
#include <QMutex>
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
#include <QRecursiveMutex>
#endif
#endif

namespace FCEU
{
	class mutex
	{
		public:
			mutex(void);
			~mutex(void);
	
			void lock(void);
			void unlock(void);
			bool tryLock(void);
			bool tryLock(int timeout);
	
		private:
	#ifdef __QT_DRIVER__
		#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
			QRecursiveMutex *mtx;
		#else
			QMutex *mtx;
		#endif
	#endif
	};

	class autoScopedLock
	{
		public:
			autoScopedLock( mutex *mtx );
			autoScopedLock( mutex &mtx );
			~autoScopedLock(void);

		private:
			mutex *m;
	};

};
