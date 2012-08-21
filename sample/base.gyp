{
  'targets' : [
    {
      'target_name': 'singleton',
      'type': 'executable',
      'sources': [
        'singleton/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'observer_list',
      'type': 'executable',
      'sources': [
        'observer_list/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'scoped_ptr',
      'type': 'executable',
      'sources': [
        'scoped_ptr/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'log',
      'type': 'executable',
      'sources': [
        'log/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'array_size',
      'type': 'executable',
      'sources': [
        'array_size/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
	  {
      'target_name': 'callback',
      'type': 'executable',
      'sources': [
        'callback/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
	  {
      'target_name': 'time',
      'type': 'executable',
      'sources': [
        'time/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'message_loop',
      'type': 'executable',
      'sources': [
        'message_loop/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'platform_thread',
      'type': 'executable',
      'sources': [
        'platform_thread/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
    {
      'target_name': 'thread',
      'type': 'executable',
      'sources': [
        'thread/main.cc',
      ],
      'dependencies': [
        '../base/base.gyp:base',
      ],
    },
  	{
      'target_name': 'testing',
      'type': 'executable',
      'sources': [
	    # Infrastructure files.
        'testing/run_all_unittests.cc',
        'testing/gtest_unittest.cc',
      ],
      'dependencies': [
        '../testing/gtest.gyp:gtest',
      ],
    },
	  {
      'target_name': 'mocking',
      'type': 'executable',
      'sources': [
	      'mocking/FooInterface.h',
		    'mocking/FooMock.h',
        'mocking/FooMain.cc',
        'mocking/Foo_test.cc',
      ],
      'dependencies': [
        '../testing/gmock.gyp:gmock',
      ],
    },
    
#    {
#      'target_name': 'notification',
#      'type': 'executable',
#      'sources': [
#        'notification/main.cc',
#      ],
#      'dependencies': [
#        '../notification/notification.gyp:*',
#        '../base/base.gyp:*',
#      ],
#    },
  ],
}
